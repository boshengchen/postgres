/* contrib/seg/seg--1.2--1.3.sql */

-- complain if script is sourced in psql, rather than via ALTER EXTENSION
\echo Use "ALTER EXTENSION seg UPDATE TO '1.3'" to load this file. \quit

--
-- Get rid of unnecessary compress and decompress support functions.
--
-- To be allowed to drop the opclass entry for a support function,
-- we must change the entry's dependency type from 'internal' to 'auto',
-- as though it were a loose member of the opfamily rather than being
-- bound into a particular opclass.  There's no SQL command for that,
-- so fake it with a manual update on kmd_depend.
--
UPDATE kmd_catalog.kmd_depend
SET deptype = 'a'
WHERE classid = 'kmd_catalog.kmd_amproc'::kmd_catalog.regclass
  AND objid =
    (SELECT objid
     FROM kmd_catalog.kmd_depend
     WHERE classid = 'kmd_catalog.kmd_amproc'::kmd_catalog.regclass
       AND refclassid = 'kmd_catalog.kmd_proc'::kmd_catalog.regclass
       AND (refobjid = 'gseg_compress(kmd_catalog.internal)'::kmd_catalog.regprocedure))
  AND refclassid = 'kmd_catalog.kmd_opclass'::kmd_catalog.regclass
  AND deptype = 'i';

ALTER OPERATOR FAMILY gist_seg_ops USING gist drop function 3 (seg);
ALTER EXTENSION seg DROP function gseg_compress(kmd_catalog.internal);
DROP function gseg_compress(kmd_catalog.internal);

UPDATE kmd_catalog.kmd_depend
SET deptype = 'a'
WHERE classid = 'kmd_catalog.kmd_amproc'::kmd_catalog.regclass
  AND objid =
    (SELECT objid
     FROM kmd_catalog.kmd_depend
     WHERE classid = 'kmd_catalog.kmd_amproc'::kmd_catalog.regclass
       AND refclassid = 'kmd_catalog.kmd_proc'::kmd_catalog.regclass
       AND (refobjid = 'gseg_decompress(kmd_catalog.internal)'::kmd_catalog.regprocedure))
  AND refclassid = 'kmd_catalog.kmd_opclass'::kmd_catalog.regclass
  AND deptype = 'i';

ALTER OPERATOR FAMILY gist_seg_ops USING gist drop function 4 (seg);
ALTER EXTENSION seg DROP function gseg_decompress(kmd_catalog.internal);
DROP function gseg_decompress(kmd_catalog.internal);
