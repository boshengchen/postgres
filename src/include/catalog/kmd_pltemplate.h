/*-------------------------------------------------------------------------
 *
 * kmd_pltemplate.h
 *	  definition of the "PL template" system catalog (kmd_pltemplate)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_pltemplate.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_PLTEMPLATE_H
#define PG_PLTEMPLATE_H

#include "catalog/genbki.h"
#include "catalog/kmd_pltemplate_d.h"

/* ----------------
 *		kmd_pltemplate definition.  cpp turns this into
 *		typedef struct FormData_kmd_pltemplate
 * ----------------
 */
CATALOG(kmd_pltemplate,1136,PLTemplateRelationId) BKI_SHARED_RELATION
{
	NameData	tmplname;		/* name of PL */
	bool		tmpltrusted;	/* PL is trusted? */
	bool		tmpldbacreate;	/* PL is installable by db owner? */

#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	text		tmplhandler BKI_FORCE_NOT_NULL; /* name of call handler
												 * function */
	text		tmplinline;		/* name of anonymous-block handler, or NULL */
	text		tmplvalidator;	/* name of validator function, or NULL */
	text		tmpllibrary BKI_FORCE_NOT_NULL; /* path of shared library */
	aclitem		tmplacl[1];		/* access privileges for template */
#endif
} FormData_kmd_pltemplate;

/* ----------------
 *		Form_kmd_pltemplate corresponds to a pointer to a row with
 *		the format of kmd_pltemplate relation.
 * ----------------
 */
typedef FormData_kmd_pltemplate *Form_kmd_pltemplate;

#endif							/* PG_PLTEMPLATE_H */
