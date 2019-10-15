/* contrib/citext/citext--1.3--1.4.sql */

-- complain if script is sourced in psql, rather than via ALTER EXTENSION
\echo Use "ALTER EXTENSION citext UPDATE TO '1.4'" to load this file. \quit

CREATE FUNCTION regexp_match( citext, citext ) RETURNS TEXT[] AS $$
    SELECT kmd_catalog.regexp_match( $1::kmd_catalog.text, $2::kmd_catalog.text, 'i' );
$$ LANGUAGE SQL IMMUTABLE STRICT PARALLEL SAFE;

CREATE FUNCTION regexp_match( citext, citext, text ) RETURNS TEXT[] AS $$
    SELECT kmd_catalog.regexp_match( $1::kmd_catalog.text, $2::kmd_catalog.text, CASE WHEN kmd_catalog.strpos($3, 'c') = 0 THEN  $3 || 'i' ELSE $3 END );
$$ LANGUAGE SQL IMMUTABLE STRICT PARALLEL SAFE;
