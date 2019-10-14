/*-------------------------------------------------------------------------
 *
 * kmd_enum.h
 *	  definition of the "enum" system catalog (kmd_enum)
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/kmd_enum.h
 *
 * NOTES
 *	  The Catalog.pm module reads this file and derives schema
 *	  information.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_ENUM_H
#define PG_ENUM_H

#include "catalog/genbki.h"
#include "catalog/kmd_enum_d.h"

#include "nodes/pg_list.h"

/* ----------------
 *		kmd_enum definition.  cpp turns this into
 *		typedef struct FormData_kmd_enum
 * ----------------
 */
CATALOG(kmd_enum,3501,EnumRelationId)
{
	Oid			oid;			/* oid */
	Oid			enumtypid;		/* OID of owning enum type */
	float4		enumsortorder;	/* sort position of this enum value */
	NameData	enumlabel;		/* text representation of enum value */
} FormData_kmd_enum;

/* ----------------
 *		Form_kmd_enum corresponds to a pointer to a tuple with
 *		the format of kmd_enum relation.
 * ----------------
 */
typedef FormData_kmd_enum *Form_kmd_enum;

/*
 * prototypes for functions in kmd_enum.c
 */
extern void EnumValuesCreate(Oid enumTypeOid, List *vals);
extern void EnumValuesDelete(Oid enumTypeOid);
extern void AddEnumLabel(Oid enumTypeOid, const char *newVal,
						 const char *neighbor, bool newValIsAfter,
						 bool skipIfExists);
extern void RenameEnumLabel(Oid enumTypeOid,
							const char *oldVal, const char *newVal);
extern bool EnumBlacklisted(Oid enum_id);
extern Size EstimateEnumBlacklistSpace(void);
extern void SerializeEnumBlacklist(void *space, Size size);
extern void RestoreEnumBlacklist(void *space);
extern void AtEOXact_Enum(void);

#endif							/* PG_ENUM_H */
