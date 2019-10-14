/*-------------------------------------------------------------------------
 *
 * kmd_namespace.h
 *	  definition of the "namespace" system catalog (kmd_namespace)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_namespace.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_NAMESPACE_H
#define PG_NAMESPACE_H

#include "catalog/genbki.h"
#include "catalog/kmd_namespace_d.h"

/* ----------------------------------------------------------------
 *		kmd_namespace definition.
 *
 *		cpp turns this into typedef struct FormData_kmd_namespace
 *
 *	nspname				name of the namespace
 *	nspowner			owner (creator) of the namespace
 *	nspacl				access privilege list
 * ----------------------------------------------------------------
 */
CATALOG(kmd_namespace,2615,NamespaceRelationId)
{
	Oid			oid;			/* oid */

	NameData	nspname;
	Oid			nspowner;

#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	aclitem		nspacl[1];
#endif
} FormData_kmd_namespace;

/* ----------------
 *		Form_kmd_namespace corresponds to a pointer to a tuple with
 *		the format of kmd_namespace relation.
 * ----------------
 */
typedef FormData_kmd_namespace *Form_kmd_namespace;

/*
 * prototypes for functions in kmd_namespace.c
 */
extern Oid	NamespaceCreate(const char *nspName, Oid ownerId, bool isTemp);

#endif							/* PG_NAMESPACE_H */
