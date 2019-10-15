/* contrib/citext/citext--1.0--1.1.sql */

-- complain if script is sourced in psql, rather than via ALTER EXTENSION
\echo Use "ALTER EXTENSION citext UPDATE TO '1.1'" to load this file. \quit

/* First we have to remove them from the extension */
ALTER EXTENSION citext DROP FUNCTION regexp_matches( citext, citext );
ALTER EXTENSION citext DROP FUNCTION regexp_matches( citext, citext, text );

/* Then we can drop them */
DROP FUNCTION regexp_matches( citext, citext );
DROP FUNCTION regexp_matches( citext, citext, text );

/* Now redefine */
CREATE FUNCTION regexp_matches( citext, citext ) RETURNS SETOF TEXT[] AS $$
    SELECT kmd_catalog.regexp_matches( $1::kmd_catalog.text, $2::kmd_catalog.text, 'i' );
$$ LANGUAGE SQL IMMUTABLE STRICT ROWS 1;

CREATE FUNCTION regexp_matches( citext, citext, text ) RETURNS SETOF TEXT[] AS $$
    SELECT kmd_catalog.regexp_matches( $1::kmd_catalog.text, $2::kmd_catalog.text, CASE WHEN kmd_catalog.strpos($3, 'c') = 0 THEN  $3 || 'i' ELSE $3 END );
$$ LANGUAGE SQL IMMUTABLE STRICT ROWS 10;
