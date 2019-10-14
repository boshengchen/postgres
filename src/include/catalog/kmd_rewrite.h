/*-------------------------------------------------------------------------
 *
 * kmd_rewrite.h
 *	  definition of the "rewrite rule" system catalog (kmd_rewrite)
 *
 * As of Postgres 7.3, the primary key for this table is <ev_class, rulename>
 * --- ie, rule names are only unique among the rules of a given table.
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_rewrite.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_REWRITE_H
#define PG_REWRITE_H

#include "catalog/genbki.h"
#include "catalog/kmd_rewrite_d.h"

/* ----------------
 *		kmd_rewrite definition.  cpp turns this into
 *		typedef struct FormData_kmd_rewrite
 * ----------------
 */
CATALOG(kmd_rewrite,2618,RewriteRelationId)
{
	Oid			oid;			/* oid */
	NameData	rulename;
	Oid			ev_class;
	char		ev_type;
	char		ev_enabled;
	bool		is_instead;

#ifdef CATALOG_VARLEN			/* variable-length fields start here */
	pg_node_tree ev_qual BKI_FORCE_NOT_NULL;
	pg_node_tree ev_action BKI_FORCE_NOT_NULL;
#endif
} FormData_kmd_rewrite;

/* ----------------
 *		Form_kmd_rewrite corresponds to a pointer to a tuple with
 *		the format of kmd_rewrite relation.
 * ----------------
 */
typedef FormData_kmd_rewrite *Form_kmd_rewrite;

#endif							/* PG_REWRITE_H */
