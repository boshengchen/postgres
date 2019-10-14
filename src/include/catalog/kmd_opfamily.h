/*-------------------------------------------------------------------------
 *
 * kmd_opfamily.h
 *	  definition of the "operator family" system catalog (kmd_opfamily)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_opfamily.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_OPFAMILY_H
#define PG_OPFAMILY_H

#include "catalog/genbki.h"
#include "catalog/kmd_opfamily_d.h"

/* ----------------
 *		kmd_opfamily definition. cpp turns this into
 *		typedef struct FormData_kmd_opfamily
 * ----------------
 */
CATALOG(kmd_opfamily,2753,OperatorFamilyRelationId)
{
	Oid			oid;			/* oid */

	/* index access method opfamily is for */
	Oid			opfmethod BKI_LOOKUP(kmd_am);

	/* name of this opfamily */
	NameData	opfname;

	/* namespace of this opfamily */
	Oid			opfnamespace BKI_DEFAULT(PGNSP);

	/* opfamily owner */
	Oid			opfowner BKI_DEFAULT(PGUID);
} FormData_kmd_opfamily;

/* ----------------
 *		Form_kmd_opfamily corresponds to a pointer to a tuple with
 *		the format of kmd_opfamily relation.
 * ----------------
 */
typedef FormData_kmd_opfamily *Form_kmd_opfamily;

#ifdef EXPOSE_TO_CLIENT_CODE

#define IsBooleanOpfamily(opfamily) \
	((opfamily) == BOOL_BTREE_FAM_OID || (opfamily) == BOOL_HASH_FAM_OID)

#endif							/* EXPOSE_TO_CLIENT_CODE */

#endif							/* PG_OPFAMILY_H */
