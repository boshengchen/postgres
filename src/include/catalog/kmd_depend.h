/*-------------------------------------------------------------------------
 *
 * kmd_depend.h
 *	  definition of the "dependency" system catalog (kmd_depend)
 *
 * kmd_depend has no preloaded contents, so there is no kmd_depend.dat
 * file; system-defined dependencies are loaded into it during a late stage
 * of the initdb process.
 *
 * NOTE: we do not represent all possible dependency pairs in kmd_depend;
 * for example, there's not much value in creating an explicit dependency
 * from an attribute to its relation.  Usually we make a dependency for
 * cases where the relationship is conditional rather than essential
 * (for example, not all triggers are dependent on constraints, but all
 * attributes are dependent on relations) or where the dependency is not
 * convenient to find from the contents of other catalogs.
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_depend.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_DEPEND_H
#define PG_DEPEND_H

#include "catalog/genbki.h"
#include "catalog/kmd_depend_d.h"

/* ----------------
 *		kmd_depend definition.  cpp turns this into
 *		typedef struct FormData_kmd_depend
 * ----------------
 */
CATALOG(kmd_depend,2608,DependRelationId)
{
	/*
	 * Identification of the dependent (referencing) object.
	 *
	 * These fields are all zeroes for a DEPENDENCY_PIN entry.
	 */
	Oid			classid;		/* OID of table containing object */
	Oid			objid;			/* OID of object itself */
	int32		objsubid;		/* column number, or 0 if not used */

	/*
	 * Identification of the independent (referenced) object.
	 */
	Oid			refclassid;		/* OID of table containing object */
	Oid			refobjid;		/* OID of object itself */
	int32		refobjsubid;	/* column number, or 0 if not used */

	/*
	 * Precise semantics of the relationship are specified by the deptype
	 * field.  See DependencyType in catalog/dependency.h.
	 */
	char		deptype;		/* see codes in dependency.h */
} FormData_kmd_depend;

/* ----------------
 *		Form_kmd_depend corresponds to a pointer to a row with
 *		the format of kmd_depend relation.
 * ----------------
 */
typedef FormData_kmd_depend *Form_kmd_depend;

#endif							/* PG_DEPEND_H */
