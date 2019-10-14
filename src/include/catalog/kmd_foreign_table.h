/*-------------------------------------------------------------------------
 *
 * kmd_foreign_table.h
 *	  definition of the "foreign table" system catalog (kmd_foreign_table)
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_foreign_table.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_FOREIGN_TABLE_H
#define PG_FOREIGN_TABLE_H

#include "catalog/genbki.h"
#include "catalog/kmd_foreign_table_d.h"

/* ----------------
 *		kmd_foreign_table definition.  cpp turns this into
 *		typedef struct FormData_kmd_foreign_table
 * ----------------
 */
CATALOG(kmd_foreign_table,3118,ForeignTableRelationId)
{
	Oid			ftrelid;		/* OID of foreign table */
	Oid			ftserver;		/* OID of foreign server */

#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	text		ftoptions[1];	/* FDW-specific options */
#endif
} FormData_kmd_foreign_table;

/* ----------------
 *		Form_kmd_foreign_table corresponds to a pointer to a tuple with
 *		the format of kmd_foreign_table relation.
 * ----------------
 */
typedef FormData_kmd_foreign_table *Form_kmd_foreign_table;

#endif							/* PG_FOREIGN_TABLE_H */
