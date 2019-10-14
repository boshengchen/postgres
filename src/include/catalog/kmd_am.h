/*-------------------------------------------------------------------------
 *
 * kmd_am.h
 *	  definition of the "access method" system catalog (kmd_am)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_am.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_AM_H
#define PG_AM_H

#include "catalog/genbki.h"
#include "catalog/kmd_am_d.h"

/* ----------------
 *		kmd_am definition.  cpp turns this into
 *		typedef struct FormData_kmd_am
 * ----------------
 */
CATALOG(kmd_am,2601,AccessMethodRelationId)
{
	Oid			oid;			/* oid */

	/* access method name */
	NameData	amname;

	/* handler function */
	regproc		amhandler BKI_LOOKUP(kmd_proc);

	/* see AMTYPE_xxx constants below */
	char		amtype;
} FormData_kmd_am;

/* ----------------
 *		Form_kmd_am corresponds to a pointer to a tuple with
 *		the format of kmd_am relation.
 * ----------------
 */
typedef FormData_kmd_am *Form_kmd_am;

#ifdef EXPOSE_TO_CLIENT_CODE

/*
 * Allowed values for amtype
 */
#define AMTYPE_INDEX					'i' /* index access method */
#define AMTYPE_TABLE					't' /* table access method */

#endif							/* EXPOSE_TO_CLIENT_CODE */

#endif							/* PG_AM_H */
