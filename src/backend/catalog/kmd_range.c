/*-------------------------------------------------------------------------
 *
 * kmd_range.c
 *	  routines to support manipulation of the kmd_range relation
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *	  src/backend/catalog/kmd_range.c
 *
 *-------------------------------------------------------------------------
 */
#include "postgres.h"

#include "access/genam.h"
#include "access/htup_details.h"
#include "access/table.h"
#include "catalog/dependency.h"
#include "catalog/indexing.h"
#include "catalog/kmd_collation.h"
#include "catalog/kmd_opclass.h"
#include "catalog/kmd_proc.h"
#include "catalog/kmd_range.h"
#include "catalog/kmd_type.h"
#include "utils/fmgroids.h"
#include "utils/rel.h"


/*
 * RangeCreate
 *		Create an entry in kmd_range.
 */
void
RangeCreate(Oid rangeTypeOid, Oid rangeSubType, Oid rangeCollation,
			Oid rangeSubOpclass, RegProcedure rangeCanonical,
			RegProcedure rangeSubDiff)
{
	Relation	kmd_range;
	Datum		values[Natts_kmd_range];
	bool		nulls[Natts_kmd_range];
	HeapTuple	tup;
	ObjectAddress myself;
	ObjectAddress referenced;

	kmd_range = table_open(RangeRelationId, RowExclusiveLock);

	memset(nulls, 0, sizeof(nulls));

	values[Anum_kmd_range_rngtypid - 1] = ObjectIdGetDatum(rangeTypeOid);
	values[Anum_kmd_range_rngsubtype - 1] = ObjectIdGetDatum(rangeSubType);
	values[Anum_kmd_range_rngcollation - 1] = ObjectIdGetDatum(rangeCollation);
	values[Anum_kmd_range_rngsubopc - 1] = ObjectIdGetDatum(rangeSubOpclass);
	values[Anum_kmd_range_rngcanonical - 1] = ObjectIdGetDatum(rangeCanonical);
	values[Anum_kmd_range_rngsubdiff - 1] = ObjectIdGetDatum(rangeSubDiff);

	tup = heap_form_tuple(RelationGetDescr(kmd_range), values, nulls);

	CatalogTupleInsert(kmd_range, tup);
	heap_freetuple(tup);

	/* record type's dependencies on range-related items */

	myself.classId = TypeRelationId;
	myself.objectId = rangeTypeOid;
	myself.objectSubId = 0;

	referenced.classId = TypeRelationId;
	referenced.objectId = rangeSubType;
	referenced.objectSubId = 0;
	recordDependencyOn(&myself, &referenced, DEPENDENCY_NORMAL);

	referenced.classId = OperatorClassRelationId;
	referenced.objectId = rangeSubOpclass;
	referenced.objectSubId = 0;
	recordDependencyOn(&myself, &referenced, DEPENDENCY_NORMAL);

	if (OidIsValid(rangeCollation))
	{
		referenced.classId = CollationRelationId;
		referenced.objectId = rangeCollation;
		referenced.objectSubId = 0;
		recordDependencyOn(&myself, &referenced, DEPENDENCY_NORMAL);
	}

	if (OidIsValid(rangeCanonical))
	{
		referenced.classId = ProcedureRelationId;
		referenced.objectId = rangeCanonical;
		referenced.objectSubId = 0;
		recordDependencyOn(&myself, &referenced, DEPENDENCY_NORMAL);
	}

	if (OidIsValid(rangeSubDiff))
	{
		referenced.classId = ProcedureRelationId;
		referenced.objectId = rangeSubDiff;
		referenced.objectSubId = 0;
		recordDependencyOn(&myself, &referenced, DEPENDENCY_NORMAL);
	}

	table_close(kmd_range, RowExclusiveLock);
}


/*
 * RangeDelete
 *		Remove the kmd_range entry for the specified type.
 */
void
RangeDelete(Oid rangeTypeOid)
{
	Relation	kmd_range;
	ScanKeyData key[1];
	SysScanDesc scan;
	HeapTuple	tup;

	kmd_range = table_open(RangeRelationId, RowExclusiveLock);

	ScanKeyInit(&key[0],
				Anum_kmd_range_rngtypid,
				BTEqualStrategyNumber, F_OIDEQ,
				ObjectIdGetDatum(rangeTypeOid));

	scan = systable_beginscan(kmd_range, RangeTypidIndexId, true,
							  NULL, 1, key);

	while (HeapTupleIsValid(tup = systable_getnext(scan)))
	{
		CatalogTupleDelete(kmd_range, &tup->t_self);
	}

	systable_endscan(scan);

	table_close(kmd_range, RowExclusiveLock);
}
