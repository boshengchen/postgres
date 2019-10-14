/*-------------------------------------------------------------------------
 *
 * kmd_ts_config.h
 *	  definition of the "text search configuration" system catalog
 *	  (kmd_ts_config)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_ts_config.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_TS_CONFIG_H
#define PG_TS_CONFIG_H

#include "catalog/genbki.h"
#include "catalog/kmd_ts_config_d.h"

/* ----------------
 *		kmd_ts_config definition.  cpp turns this into
 *		typedef struct FormData_kmd_ts_config
 * ----------------
 */
CATALOG(kmd_ts_config,3602,TSConfigRelationId)
{
	/* oid */
	Oid			oid;

	/* name of configuration */
	NameData	cfgname;

	/* name space */
	Oid			cfgnamespace BKI_DEFAULT(PGNSP);

	/* owner */
	Oid			cfgowner BKI_DEFAULT(PGUID);

	/* OID of parser */
	Oid			cfgparser BKI_LOOKUP(kmd_ts_parser);
} FormData_kmd_ts_config;

typedef FormData_kmd_ts_config *Form_kmd_ts_config;

#endif							/* PG_TS_CONFIG_H */
