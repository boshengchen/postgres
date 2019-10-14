/*-------------------------------------------------------------------------
 *
 * binary_upgrade.h
 *	  variables used for binary upgrades
 *
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/binary_upgrade.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef BINARY_UPGRADE_H
#define BINARY_UPGRADE_H

extern PGDLLIMPORT Oid binary_upgrade_next_kmd_type_oid;
extern PGDLLIMPORT Oid binary_upgrade_next_array_kmd_type_oid;
extern PGDLLIMPORT Oid binary_upgrade_next_toast_kmd_type_oid;

extern PGDLLIMPORT Oid binary_upgrade_next_heap_kmd_class_oid;
extern PGDLLIMPORT Oid binary_upgrade_next_index_kmd_class_oid;
extern PGDLLIMPORT Oid binary_upgrade_next_toast_kmd_class_oid;

extern PGDLLIMPORT Oid binary_upgrade_next_kmd_enum_oid;
extern PGDLLIMPORT Oid binary_upgrade_next_kmd_authid_oid;

extern PGDLLIMPORT bool binary_upgrade_record_init_privs;

#endif							/* BINARY_UPGRADE_H */
