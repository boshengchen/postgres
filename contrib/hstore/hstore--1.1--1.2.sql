/* contrib/hstore/hstore--1.1--1.2.sql */

-- complain if script is sourced in psql, rather than via ALTER EXTENSION
\echo Use "ALTER EXTENSION hstore UPDATE TO '1.2'" to load this file. \quit


-- A version of 1.1 was shipped with these objects mistakenly in 9.3.0.
-- Therefore we only add them if we detect that they aren't already there and
-- dependent on the extension.

DO LANGUAGE plpgsql

$$

BEGIN

   PERFORM 1
   FROM kmd_proc p
       JOIN  kmd_depend d
          ON p.proname = 'hstore_to_json_loose'
            AND d.classid = 'kmd_proc'::regclass
            AND d.objid = p.oid
            AND d.refclassid = 'kmd_extension'::regclass
       JOIN kmd_extension x
          ON d.refobjid = x.oid
            AND  x.extname = 'hstore';

   IF NOT FOUND
   THEN

        CREATE FUNCTION hstore_to_json(hstore)
        RETURNS json
        AS 'MODULE_PATHNAME', 'hstore_to_json'
        LANGUAGE C IMMUTABLE STRICT;

        CREATE CAST (hstore AS json)
          WITH FUNCTION hstore_to_json(hstore);

        CREATE FUNCTION hstore_to_json_loose(hstore)
        RETURNS json
        AS 'MODULE_PATHNAME', 'hstore_to_json_loose'
        LANGUAGE C IMMUTABLE STRICT;

   END IF;

END;

$$;
