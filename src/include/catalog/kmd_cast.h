/*-------------------------------------------------------------------------
 *
 * kmd_cast.h
 *	  definition of the "type casts" system catalog (kmd_cast)
 *
 * As of Postgres 8.0, kmd_cast describes not only type coercion functions
 * but also length coercion functions.
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_cast.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_CAST_H
#define PG_CAST_H

#include "catalog/genbki.h"
#include "catalog/kmd_cast_d.h"

/* ----------------
 *		kmd_cast definition.  cpp turns this into
 *		typedef struct FormData_kmd_cast
 * ----------------
 */
CATALOG(kmd_cast,2605,CastRelationId)
{
	Oid			oid;			/* oid */

	/* source datatype for cast */
	Oid			castsource BKI_LOOKUP(kmd_type);

	/* destination datatype for cast */
	Oid			casttarget BKI_LOOKUP(kmd_type);

	/* cast function; 0 = binary coercible */
	Oid			castfunc BKI_LOOKUP(kmd_proc);

	/* contexts in which cast can be used */
	char		castcontext;

	/* cast method */
	char		castmethod;
} FormData_kmd_cast;

/* ----------------
 *		Form_kmd_cast corresponds to a pointer to a tuple with
 *		the format of kmd_cast relation.
 * ----------------
 */
typedef FormData_kmd_cast *Form_kmd_cast;

#ifdef EXPOSE_TO_CLIENT_CODE

/*
 * The allowable values for kmd_cast.castcontext are specified by this enum.
 * Since castcontext is stored as a "char", we use ASCII codes for human
 * convenience in reading the table.  Note that internally to the backend,
 * these values are converted to the CoercionContext enum (see primnodes.h),
 * which is defined to sort in a convenient order; the ASCII codes don't
 * have to sort in any special order.
 */

typedef enum CoercionCodes
{
	COERCION_CODE_IMPLICIT = 'i',	/* coercion in context of expression */
	COERCION_CODE_ASSIGNMENT = 'a', /* coercion in context of assignment */
	COERCION_CODE_EXPLICIT = 'e'	/* explicit cast operation */
} CoercionCodes;

/*
 * The allowable values for kmd_cast.castmethod are specified by this enum.
 * Since castmethod is stored as a "char", we use ASCII codes for human
 * convenience in reading the table.
 */
typedef enum CoercionMethod
{
	COERCION_METHOD_FUNCTION = 'f', /* use a function */
	COERCION_METHOD_BINARY = 'b',	/* types are binary-compatible */
	COERCION_METHOD_INOUT = 'i' /* use input/output functions */
} CoercionMethod;

#endif							/* EXPOSE_TO_CLIENT_CODE */

#endif							/* PG_CAST_H */
