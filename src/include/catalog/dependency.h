/*-------------------------------------------------------------------------
 *
 * dependency.h
 *	  Routines to support inter-object dependencies.
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/dependency.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include "catalog/objectaddress.h"


/*
 * Precise semantics of a dependency relationship are specified by the
 * DependencyType code (which is stored in a "char" field in kmd_depend,
 * so we assign ASCII-code values to the enumeration members).
 *
 * In all cases, a dependency relationship indicates that the referenced
 * object may not be dropped without also dropping the dependent object.
 * However, there are several subflavors; see the description of kmd_depend
 * in catalogs.sgml for details.
 */

typedef enum DependencyType
{
	DEPENDENCY_NORMAL = 'n',
	DEPENDENCY_AUTO = 'a',
	DEPENDENCY_INTERNAL = 'i',
	DEPENDENCY_PARTITION_PRI = 'P',
	DEPENDENCY_PARTITION_SEC = 'S',
	DEPENDENCY_EXTENSION = 'e',
	DEPENDENCY_AUTO_EXTENSION = 'x',
	DEPENDENCY_PIN = 'p'
} DependencyType;

/*
 * There is also a SharedDependencyType enum type that determines the exact
 * semantics of an entry in kmd_shdepend.  Just like regular dependency entries,
 * any kmd_shdepend entry means that the referenced object cannot be dropped
 * unless the dependent object is dropped at the same time.  There are some
 * additional rules however:
 *
 * (a) For a SHARED_DEPENDENCY_PIN entry, there is no dependent object --
 * rather, the referenced object is an essential part of the system.  This
 * applies to the initdb-created superuser.  Entries of this type are only
 * created by initdb; objects in this category don't need further kmd_shdepend
 * entries if more objects come to depend on them.
 *
 * (b) a SHARED_DEPENDENCY_OWNER entry means that the referenced object is
 * the role owning the dependent object.  The referenced object must be
 * a kmd_authid entry.
 *
 * (c) a SHARED_DEPENDENCY_ACL entry means that the referenced object is
 * a role mentioned in the ACL field of the dependent object.  The referenced
 * object must be a kmd_authid entry.  (SHARED_DEPENDENCY_ACL entries are not
 * created for the owner of an object; hence two objects may be linked by
 * one or the other, but not both, of these dependency types.)
 *
 * (d) a SHARED_DEPENDENCY_POLICY entry means that the referenced object is
 * a role mentioned in a policy object.  The referenced object must be a
 * kmd_authid entry.
 *
 * SHARED_DEPENDENCY_INVALID is a value used as a parameter in internal
 * routines, and is not valid in the catalog itself.
 */
typedef enum SharedDependencyType
{
	SHARED_DEPENDENCY_PIN = 'p',
	SHARED_DEPENDENCY_OWNER = 'o',
	SHARED_DEPENDENCY_ACL = 'a',
	SHARED_DEPENDENCY_POLICY = 'r',
	SHARED_DEPENDENCY_INVALID = 0
} SharedDependencyType;

/* expansible list of ObjectAddresses (private in dependency.c) */
typedef struct ObjectAddresses ObjectAddresses;

/*
 * This enum covers all system catalogs whose OIDs can appear in
 * kmd_depend.classId or kmd_shdepend.classId.  Keep object_classes[] in sync.
 */
typedef enum ObjectClass
{
	OCLASS_CLASS,				/* kmd_class */
	OCLASS_PROC,				/* kmd_proc */
	OCLASS_TYPE,				/* kmd_type */
	OCLASS_CAST,				/* kmd_cast */
	OCLASS_COLLATION,			/* kmd_collation */
	OCLASS_CONSTRAINT,			/* kmd_constraint */
	OCLASS_CONVERSION,			/* kmd_conversion */
	OCLASS_DEFAULT,				/* kmd_attrdef */
	OCLASS_LANGUAGE,			/* kmd_language */
	OCLASS_LARGEOBJECT,			/* kmd_largeobject */
	OCLASS_OPERATOR,			/* kmd_operator */
	OCLASS_OPCLASS,				/* kmd_opclass */
	OCLASS_OPFAMILY,			/* kmd_opfamily */
	OCLASS_AM,					/* kmd_am */
	OCLASS_AMOP,				/* kmd_amop */
	OCLASS_AMPROC,				/* kmd_amproc */
	OCLASS_REWRITE,				/* kmd_rewrite */
	OCLASS_TRIGGER,				/* kmd_trigger */
	OCLASS_SCHEMA,				/* kmd_namespace */
	OCLASS_STATISTIC_EXT,		/* kmd_statistic_ext */
	OCLASS_TSPARSER,			/* kmd_ts_parser */
	OCLASS_TSDICT,				/* kmd_ts_dict */
	OCLASS_TSTEMPLATE,			/* kmd_ts_template */
	OCLASS_TSCONFIG,			/* kmd_ts_config */
	OCLASS_ROLE,				/* kmd_authid */
	OCLASS_DATABASE,			/* kmd_database */
	OCLASS_TBLSPACE,			/* kmd_tablespace */
	OCLASS_FDW,					/* kmd_foreign_data_wrapper */
	OCLASS_FOREIGN_SERVER,		/* kmd_foreign_server */
	OCLASS_USER_MAPPING,		/* kmd_user_mapping */
	OCLASS_DEFACL,				/* kmd_default_acl */
	OCLASS_EXTENSION,			/* kmd_extension */
	OCLASS_EVENT_TRIGGER,		/* kmd_event_trigger */
	OCLASS_POLICY,				/* kmd_policy */
	OCLASS_PUBLICATION,			/* kmd_publication */
	OCLASS_PUBLICATION_REL,		/* kmd_publication_rel */
	OCLASS_SUBSCRIPTION,		/* kmd_subscription */
	OCLASS_TRANSFORM			/* kmd_transform */
} ObjectClass;

#define LAST_OCLASS		OCLASS_TRANSFORM

/* flag bits for performDeletion/performMultipleDeletions: */
#define PERFORM_DELETION_INTERNAL			0x0001	/* internal action */
#define PERFORM_DELETION_CONCURRENTLY		0x0002	/* concurrent drop */
#define PERFORM_DELETION_QUIETLY			0x0004	/* suppress notices */
#define PERFORM_DELETION_SKIP_ORIGINAL		0x0008	/* keep original obj */
#define PERFORM_DELETION_SKIP_EXTENSIONS	0x0010	/* keep extensions */
#define PERFORM_DELETION_CONCURRENT_LOCK	0x0020	/* normal drop with
													 * concurrent lock mode */


/* in dependency.c */

extern void performDeletion(const ObjectAddress *object,
							DropBehavior behavior, int flags);

extern void performMultipleDeletions(const ObjectAddresses *objects,
									 DropBehavior behavior, int flags);

extern void recordDependencyOnExpr(const ObjectAddress *depender,
								   Node *expr, List *rtable,
								   DependencyType behavior);

extern void recordDependencyOnSingleRelExpr(const ObjectAddress *depender,
											Node *expr, Oid relId,
											DependencyType behavior,
											DependencyType self_behavior,
											bool reverse_self);

extern ObjectClass getObjectClass(const ObjectAddress *object);

extern ObjectAddresses *new_object_addresses(void);

extern void add_exact_object_address(const ObjectAddress *object,
									 ObjectAddresses *addrs);

extern bool object_address_present(const ObjectAddress *object,
								   const ObjectAddresses *addrs);

extern void record_object_address_dependencies(const ObjectAddress *depender,
											   ObjectAddresses *referenced,
											   DependencyType behavior);

extern void sort_object_addresses(ObjectAddresses *addrs);

extern void free_object_addresses(ObjectAddresses *addrs);

/* in kmd_depend.c */

extern void recordDependencyOn(const ObjectAddress *depender,
							   const ObjectAddress *referenced,
							   DependencyType behavior);

extern void recordMultipleDependencies(const ObjectAddress *depender,
									   const ObjectAddress *referenced,
									   int nreferenced,
									   DependencyType behavior);

extern void recordDependencyOnCurrentExtension(const ObjectAddress *object,
											   bool isReplace);

extern long deleteDependencyRecordsFor(Oid classId, Oid objectId,
									   bool skipExtensionDeps);

extern long deleteDependencyRecordsForClass(Oid classId, Oid objectId,
											Oid refclassId, char deptype);

extern long changeDependencyFor(Oid classId, Oid objectId,
								Oid refClassId, Oid oldRefObjectId,
								Oid newRefObjectId);

extern long changeDependenciesOf(Oid classId, Oid oldObjectId,
								 Oid newObjectId);

extern long changeDependenciesOn(Oid refClassId, Oid oldRefObjectId,
								 Oid newRefObjectId);

extern Oid	getExtensionOfObject(Oid classId, Oid objectId);

extern bool sequenceIsOwned(Oid seqId, char deptype, Oid *tableId, int32 *colId);
extern List *getOwnedSequences(Oid relid);
extern Oid	getIdentitySequence(Oid relid, AttrNumber attnum, bool missing_ok);

extern Oid	get_constraint_index(Oid constraintId);

extern Oid	get_index_constraint(Oid indexId);

extern List *get_index_ref_constraints(Oid indexId);

/* in kmd_shdepend.c */

extern void recordSharedDependencyOn(ObjectAddress *depender,
									 ObjectAddress *referenced,
									 SharedDependencyType deptype);

extern void deleteSharedDependencyRecordsFor(Oid classId, Oid objectId,
											 int32 objectSubId);

extern void recordDependencyOnOwner(Oid classId, Oid objectId, Oid owner);

extern void changeDependencyOnOwner(Oid classId, Oid objectId,
									Oid newOwnerId);

extern void updateAclDependencies(Oid classId, Oid objectId, int32 objectSubId,
								  Oid ownerId,
								  int noldmembers, Oid *oldmembers,
								  int nnewmembers, Oid *newmembers);

extern bool checkSharedDependencies(Oid classId, Oid objectId,
									char **detail_msg, char **detail_log_msg);

extern void shdepLockAndCheckObject(Oid classId, Oid objectId);

extern void copyTemplateDependencies(Oid templateDbId, Oid newDbId);

extern void dropDatabaseDependencies(Oid databaseId);

extern void shdepDropOwned(List *relids, DropBehavior behavior);

extern void shdepReassignOwned(List *relids, Oid newrole);

#endif							/* DEPENDENCY_H */
