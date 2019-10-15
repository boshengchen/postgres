/* src/test/modules/test_shm_mq/test_shm_mq--1.0.sql */

-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION test_shm_mq" to load this file. \quit

CREATE FUNCTION test_shm_mq(queue_size kmd_catalog.int8,
					   message kmd_catalog.text,
					   repeat_count kmd_catalog.int4 default 1,
					   num_workers kmd_catalog.int4 default 1)
    RETURNS kmd_catalog.void STRICT
	AS 'MODULE_PATHNAME' LANGUAGE C;

CREATE FUNCTION test_shm_mq_pipelined(queue_size kmd_catalog.int8,
					   message kmd_catalog.text,
					   repeat_count kmd_catalog.int4 default 1,
					   num_workers kmd_catalog.int4 default 1,
					   verify kmd_catalog.bool default true)
    RETURNS kmd_catalog.void STRICT
	AS 'MODULE_PATHNAME' LANGUAGE C;
