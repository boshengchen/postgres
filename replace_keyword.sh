#!/bin/bash

keywords=(\
"attrdef"\
"attribute" \
"authid" \
"auth_members" \
"available_extensions" \
"cast" \
"class" \
"collation" \
"config" \
"constraint" \
"conversion" \
"cursors" \
"database" \
"db_role_setting" \
"default_acl" \
"depend" \
"description" \
"enum" \
"event_trigger" \
"extension" \
"file_settings" \
"foreign_data_wrapper" \
"foreign_server" \
"foreign_table" \
"group" \
"hba_file_rules" \
"index" \
"indexes" \
"inherits" \
"init_privs" \
"language" \
"largeobject" \
"largeobject_metadata" \
"locks" \
"matviews" \
"namespace" \
"opclass" \
"operator" \
"opfamily" \
"partitioned_table" \
"pltemplate" \
"policies" \
"policy" \
"prepared_statements" \
"prepared_xacts" \
"proc" \
"publication" \
"publication_rel" \
"publication_tables" \
"range" \
"replication_origin" \
"replication_origin_status" \
"replication_slots" \
"rewrite" \
"roles" \
"rules" \
"seclabel" \
"seclabels" \
"sequence" \
"sequences" \
"settings" \
"shadow" \
"shdepend" \
"shdescription" \
"shseclabel" \
"stat_activity" \
"stat_all_indexes" \
"stat_all_tables" \
"stat_archiver" \
"stat_bgwriter" \
"stat_database" \
"stat_database_conflicts" \
"stat_gssapi" \
"statio_all_indexes" \
"statio_all_sequences" \
"statio_all_tables" \
"statio_sys_indexes" \
"statio_sys_sequences" \
"statio_sys_tables" \
"statio_user_indexes" \
"statio_user_sequences" \
"statio_user_tables" \
"statistic" \
"statistic_ext" \
"statistic_ext_data" \
"stat_progress_cluster" \
"stat_progress_create_index" \
"stat_progress_vacuum" \
"stat_replication" \
"stats" \
"stats_ext" \
"stat_ssl" \
"stat_subscription" \
"stat_sys_indexes" \
"stat_sys_tables" \
"stat_user_functions" \
"stat_user_indexes" \
"stat_user_tables" \
"stat_wal_receiver" \
"stat_xact_all_tables" \
"stat_xact_sys_tables" \
"stat_xact_user_functions" \
"stat_xact_user_tables" \
"subscription" \
"subscription_rel" \
"tables" \
"tablespace" \
"timezone_abbrevs" \
"timezone_names" \
"transform" \
"trigger" \
"ts_config" \
"ts_config_map" \
"ts_dict" \
"ts_parser" \
"ts_template" \
"type" \
"user" \
"user_mapping" \
"user_mappings" \
"views" \
)

#or str in ${keywords[@]};do
#sed -i "s/pg_$str/kmd_$str/g"  `grep "pg_$str" -rl --exclude-dir=.git* ./`
#done

for str in ${keywords[@]};do
find ./ -name "pg_$str*" -exec rename pg_$str kmd_$str {} \;
done

