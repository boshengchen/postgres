/*-------------------------------------------------------------------------
 *
 * kmd_constraint_d.h
 *    Macro definitions for kmd_constraint
 *
 * Portions Copyright (c) 1996-2019, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * NOTES
 *  ******************************
 *  *** DO NOT EDIT THIS FILE! ***
 *  ******************************
 *
 *  It has been GENERATED by src/backend/catalog/genbki.pl
 *
 *-------------------------------------------------------------------------
 */
#ifndef KMD_CONSTRAINT_D_H
#define KMD_CONSTRAINT_D_H

#define ConstraintRelationId 2606

#define Anum_kmd_constraint_oid 1
#define Anum_kmd_constraint_conname 2
#define Anum_kmd_constraint_connamespace 3
#define Anum_kmd_constraint_contype 4
#define Anum_kmd_constraint_condeferrable 5
#define Anum_kmd_constraint_condeferred 6
#define Anum_kmd_constraint_convalidated 7
#define Anum_kmd_constraint_conrelid 8
#define Anum_kmd_constraint_contypid 9
#define Anum_kmd_constraint_conindid 10
#define Anum_kmd_constraint_conparentid 11
#define Anum_kmd_constraint_confrelid 12
#define Anum_kmd_constraint_confupdtype 13
#define Anum_kmd_constraint_confdeltype 14
#define Anum_kmd_constraint_confmatchtype 15
#define Anum_kmd_constraint_conislocal 16
#define Anum_kmd_constraint_coninhcount 17
#define Anum_kmd_constraint_connoinherit 18
#define Anum_kmd_constraint_conkey 19
#define Anum_kmd_constraint_confkey 20
#define Anum_kmd_constraint_conpfeqop 21
#define Anum_kmd_constraint_conppeqop 22
#define Anum_kmd_constraint_conffeqop 23
#define Anum_kmd_constraint_conexclop 24
#define Anum_kmd_constraint_conbin 25

#define Natts_kmd_constraint 25


/* Valid values for contype */
#define CONSTRAINT_CHECK			'c'
#define CONSTRAINT_FOREIGN			'f'
#define CONSTRAINT_PRIMARY			'p'
#define CONSTRAINT_UNIQUE			'u'
#define CONSTRAINT_TRIGGER			't'
#define CONSTRAINT_EXCLUSION		'x'

/*
 * Valid values for confupdtype and confdeltype are the FKCONSTR_ACTION_xxx
 * constants defined in parsenodes.h.  Valid values for confmatchtype are
 * the FKCONSTR_MATCH_xxx constants defined in parsenodes.h.
 */


#endif							/* KMD_CONSTRAINT_D_H */