/* -------------------------------------------------------------------------
 *
 * kmd_shseclabel.h
 *	  definition of the "shared security label" system catalog (kmd_shseclabel)
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_shseclabel.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 * -------------------------------------------------------------------------
 */
#ifndef PG_SHSECLABEL_H
#define PG_SHSECLABEL_H

#include "catalog/genbki.h"
#include "catalog/kmd_shseclabel_d.h"

/* ----------------
 *		kmd_shseclabel definition. cpp turns this into
 *		typedef struct FormData_kmd_shseclabel
 * ----------------
 */
CATALOG(kmd_shseclabel,3592,SharedSecLabelRelationId) BKI_SHARED_RELATION BKI_ROWTYPE_OID(4066,SharedSecLabelRelation_Rowtype_Id) BKI_SCHEMA_MACRO
{
	Oid			objoid;			/* OID of the shared object itself */
	Oid			classoid;		/* OID of table containing the shared object */

#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	text		provider BKI_FORCE_NOT_NULL;	/* name of label provider */
	text		label BKI_FORCE_NOT_NULL;	/* security label of the object */
#endif
} FormData_kmd_shseclabel;

typedef FormData_kmd_shseclabel * Form_kmd_shseclabel;

#endif							/* PG_SHSECLABEL_H */
