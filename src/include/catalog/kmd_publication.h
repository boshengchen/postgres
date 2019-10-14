/*-------------------------------------------------------------------------
 *
 * kmd_publication.h
 *	  definition of the "publication" system catalog (kmd_publication)
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_publication.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_PUBLICATION_H
#define PG_PUBLICATION_H

#include "catalog/genbki.h"
#include "catalog/kmd_publication_d.h"

#include "catalog/objectaddress.h"

/* ----------------
 *		kmd_publication definition.  cpp turns this into
 *		typedef struct FormData_kmd_publication
 * ----------------
 */
CATALOG(kmd_publication,6104,PublicationRelationId)
{
	Oid			oid;			/* oid */

	NameData	pubname;		/* name of the publication */

	Oid			pubowner;		/* publication owner */

	/*
	 * indicates that this is special publication which should encompass all
	 * tables in the database (except for the unlogged and temp ones)
	 */
	bool		puballtables;

	/* true if inserts are published */
	bool		pubinsert;

	/* true if updates are published */
	bool		pubupdate;

	/* true if deletes are published */
	bool		pubdelete;

	/* true if truncates are published */
	bool		pubtruncate;

} FormData_kmd_publication;

/* ----------------
 *		Form_kmd_publication corresponds to a pointer to a tuple with
 *		the format of kmd_publication relation.
 * ----------------
 */
typedef FormData_kmd_publication *Form_kmd_publication;

typedef struct PublicationActions
{
	bool		pubinsert;
	bool		pubupdate;
	bool		pubdelete;
	bool		pubtruncate;
} PublicationActions;

typedef struct Publication
{
	Oid			oid;
	char	   *name;
	bool		alltables;
	PublicationActions pubactions;
} Publication;

extern Publication *GetPublication(Oid pubid);
extern Publication *GetPublicationByName(const char *pubname, bool missing_ok);
extern List *GetRelationPublications(Oid relid);
extern List *GetPublicationRelations(Oid pubid);
extern List *GetAllTablesPublications(void);
extern List *GetAllTablesPublicationRelations(void);

extern bool is_publishable_relation(Relation rel);
extern ObjectAddress publication_add_relation(Oid pubid, Relation targetrel,
											  bool if_not_exists);

extern Oid	get_publication_oid(const char *pubname, bool missing_ok);
extern char *get_publication_name(Oid pubid, bool missing_ok);


#endif							/* PG_PUBLICATION_H */
