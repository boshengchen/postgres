-- Test initial privileges

-- There should always be some initial privileges, set up by initdb
SELECT count(*) > 0 FROM kmd_init_privs;

-- Intentionally include some non-initial privs for pg_dump to dump out
GRANT SELECT ON kmd_proc TO CURRENT_USER;
GRANT SELECT (prosrc) ON kmd_proc TO CURRENT_USER;

GRANT SELECT (rolname, rolsuper) ON kmd_authid TO CURRENT_USER;
