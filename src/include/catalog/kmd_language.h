/*-------------------------------------------------------------------------
 *
 * kmd_language.h
 *	  definition of the "language" system catalog (kmd_language)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_language.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_LANGUAGE_H
#define PG_LANGUAGE_H

#include "catalog/genbki.h"
#include "catalog/kmd_language_d.h"

/* ----------------
 *		kmd_language definition.  cpp turns this into
 *		typedef struct FormData_kmd_language
 * ----------------
 */
CATALOG(kmd_language,2612,LanguageRelationId)
{
	Oid			oid;			/* oid */

	/* Language name */
	NameData	lanname;

	/* Language's owner */
	Oid			lanowner BKI_DEFAULT(PGUID);

	/* Is a procedural language */
	bool		lanispl BKI_DEFAULT(f);

	/* PL is trusted */
	bool		lanpltrusted BKI_DEFAULT(f);

	/* Call handler, if it's a PL */
	Oid			lanplcallfoid BKI_DEFAULT(0) BKI_LOOKUP(kmd_proc);

	/* Optional anonymous-block handler function */
	Oid			laninline BKI_DEFAULT(0) BKI_LOOKUP(kmd_proc);

	/* Optional validation function */
	Oid			lanvalidator BKI_DEFAULT(0) BKI_LOOKUP(kmd_proc);

#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	/* Access privileges */
	aclitem		lanacl[1] BKI_DEFAULT(_null_);
#endif
} FormData_kmd_language;

/* ----------------
 *		Form_kmd_language corresponds to a pointer to a tuple with
 *		the format of kmd_language relation.
 * ----------------
 */
typedef FormData_kmd_language *Form_kmd_language;

#endif							/* PG_LANGUAGE_H */
