--
-- This is created by pgsql/src/tools/findoidjoins/make_oidjoins_check
--
SELECT	ctid, aggfnoid
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggfnoid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.aggfnoid);
SELECT	ctid, aggtransfn
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggtransfn != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.aggtransfn);
SELECT	ctid, aggfinalfn
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggfinalfn != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.aggfinalfn);
SELECT	ctid, aggcombinefn
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggcombinefn != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.aggcombinefn);
SELECT	ctid, aggserialfn
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggserialfn != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.aggserialfn);
SELECT	ctid, aggdeserialfn
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggdeserialfn != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.aggdeserialfn);
SELECT	ctid, aggmtransfn
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggmtransfn != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.aggmtransfn);
SELECT	ctid, aggminvtransfn
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggminvtransfn != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.aggminvtransfn);
SELECT	ctid, aggmfinalfn
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggmfinalfn != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.aggmfinalfn);
SELECT	ctid, aggsortop
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggsortop != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.aggsortop);
SELECT	ctid, aggtranstype
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggtranstype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.aggtranstype);
SELECT	ctid, aggmtranstype
FROM	kmd_catalog.kmd_aggregate fk
WHERE	aggmtranstype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.aggmtranstype);
SELECT	ctid, amhandler
FROM	kmd_catalog.kmd_am fk
WHERE	amhandler != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.amhandler);
SELECT	ctid, amopfamily
FROM	kmd_catalog.kmd_amop fk
WHERE	amopfamily != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_opfamily pk WHERE pk.oid = fk.amopfamily);
SELECT	ctid, amoplefttype
FROM	kmd_catalog.kmd_amop fk
WHERE	amoplefttype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.amoplefttype);
SELECT	ctid, amoprighttype
FROM	kmd_catalog.kmd_amop fk
WHERE	amoprighttype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.amoprighttype);
SELECT	ctid, amopopr
FROM	kmd_catalog.kmd_amop fk
WHERE	amopopr != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.amopopr);
SELECT	ctid, amopmethod
FROM	kmd_catalog.kmd_amop fk
WHERE	amopmethod != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_am pk WHERE pk.oid = fk.amopmethod);
SELECT	ctid, amopsortfamily
FROM	kmd_catalog.kmd_amop fk
WHERE	amopsortfamily != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_opfamily pk WHERE pk.oid = fk.amopsortfamily);
SELECT	ctid, amprocfamily
FROM	kmd_catalog.kmd_amproc fk
WHERE	amprocfamily != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_opfamily pk WHERE pk.oid = fk.amprocfamily);
SELECT	ctid, amproclefttype
FROM	kmd_catalog.kmd_amproc fk
WHERE	amproclefttype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.amproclefttype);
SELECT	ctid, amprocrighttype
FROM	kmd_catalog.kmd_amproc fk
WHERE	amprocrighttype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.amprocrighttype);
SELECT	ctid, amproc
FROM	kmd_catalog.kmd_amproc fk
WHERE	amproc != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.amproc);
SELECT	ctid, adrelid
FROM	kmd_catalog.kmd_attrdef fk
WHERE	adrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.adrelid);
SELECT	ctid, attrelid
FROM	kmd_catalog.kmd_attribute fk
WHERE	attrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.attrelid);
SELECT	ctid, atttypid
FROM	kmd_catalog.kmd_attribute fk
WHERE	atttypid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.atttypid);
SELECT	ctid, attcollation
FROM	kmd_catalog.kmd_attribute fk
WHERE	attcollation != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_collation pk WHERE pk.oid = fk.attcollation);
SELECT	ctid, roleid
FROM	kmd_catalog.kmd_auth_members fk
WHERE	roleid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.roleid);
SELECT	ctid, member
FROM	kmd_catalog.kmd_auth_members fk
WHERE	member != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.member);
SELECT	ctid, grantor
FROM	kmd_catalog.kmd_auth_members fk
WHERE	grantor != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.grantor);
SELECT	ctid, castsource
FROM	kmd_catalog.kmd_cast fk
WHERE	castsource != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.castsource);
SELECT	ctid, casttarget
FROM	kmd_catalog.kmd_cast fk
WHERE	casttarget != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.casttarget);
SELECT	ctid, castfunc
FROM	kmd_catalog.kmd_cast fk
WHERE	castfunc != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.castfunc);
SELECT	ctid, relnamespace
FROM	kmd_catalog.kmd_class fk
WHERE	relnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.relnamespace);
SELECT	ctid, reltype
FROM	kmd_catalog.kmd_class fk
WHERE	reltype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.reltype);
SELECT	ctid, reloftype
FROM	kmd_catalog.kmd_class fk
WHERE	reloftype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.reloftype);
SELECT	ctid, relowner
FROM	kmd_catalog.kmd_class fk
WHERE	relowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.relowner);
SELECT	ctid, relam
FROM	kmd_catalog.kmd_class fk
WHERE	relam != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_am pk WHERE pk.oid = fk.relam);
SELECT	ctid, reltablespace
FROM	kmd_catalog.kmd_class fk
WHERE	reltablespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_tablespace pk WHERE pk.oid = fk.reltablespace);
SELECT	ctid, reltoastrelid
FROM	kmd_catalog.kmd_class fk
WHERE	reltoastrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.reltoastrelid);
SELECT	ctid, collnamespace
FROM	kmd_catalog.kmd_collation fk
WHERE	collnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.collnamespace);
SELECT	ctid, collowner
FROM	kmd_catalog.kmd_collation fk
WHERE	collowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.collowner);
SELECT	ctid, connamespace
FROM	kmd_catalog.kmd_constraint fk
WHERE	connamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.connamespace);
SELECT	ctid, conrelid
FROM	kmd_catalog.kmd_constraint fk
WHERE	conrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.conrelid);
SELECT	ctid, contypid
FROM	kmd_catalog.kmd_constraint fk
WHERE	contypid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.contypid);
SELECT	ctid, conindid
FROM	kmd_catalog.kmd_constraint fk
WHERE	conindid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.conindid);
SELECT	ctid, conparentid
FROM	kmd_catalog.kmd_constraint fk
WHERE	conparentid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_constraint pk WHERE pk.oid = fk.conparentid);
SELECT	ctid, confrelid
FROM	kmd_catalog.kmd_constraint fk
WHERE	confrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.confrelid);
SELECT	ctid, connamespace
FROM	kmd_catalog.kmd_conversion fk
WHERE	connamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.connamespace);
SELECT	ctid, conowner
FROM	kmd_catalog.kmd_conversion fk
WHERE	conowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.conowner);
SELECT	ctid, conproc
FROM	kmd_catalog.kmd_conversion fk
WHERE	conproc != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.conproc);
SELECT	ctid, datdba
FROM	kmd_catalog.kmd_database fk
WHERE	datdba != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.datdba);
SELECT	ctid, dattablespace
FROM	kmd_catalog.kmd_database fk
WHERE	dattablespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_tablespace pk WHERE pk.oid = fk.dattablespace);
SELECT	ctid, setdatabase
FROM	kmd_catalog.kmd_db_role_setting fk
WHERE	setdatabase != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_database pk WHERE pk.oid = fk.setdatabase);
SELECT	ctid, classid
FROM	kmd_catalog.kmd_depend fk
WHERE	classid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.classid);
SELECT	ctid, refclassid
FROM	kmd_catalog.kmd_depend fk
WHERE	refclassid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.refclassid);
SELECT	ctid, classoid
FROM	kmd_catalog.kmd_description fk
WHERE	classoid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.classoid);
SELECT	ctid, enumtypid
FROM	kmd_catalog.kmd_enum fk
WHERE	enumtypid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.enumtypid);
SELECT	ctid, extowner
FROM	kmd_catalog.kmd_extension fk
WHERE	extowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.extowner);
SELECT	ctid, extnamespace
FROM	kmd_catalog.kmd_extension fk
WHERE	extnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.extnamespace);
SELECT	ctid, fdwowner
FROM	kmd_catalog.kmd_foreign_data_wrapper fk
WHERE	fdwowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.fdwowner);
SELECT	ctid, srvowner
FROM	kmd_catalog.kmd_foreign_server fk
WHERE	srvowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.srvowner);
SELECT	ctid, srvfdw
FROM	kmd_catalog.kmd_foreign_server fk
WHERE	srvfdw != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_foreign_data_wrapper pk WHERE pk.oid = fk.srvfdw);
SELECT	ctid, indexrelid
FROM	kmd_catalog.kmd_index fk
WHERE	indexrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.indexrelid);
SELECT	ctid, indrelid
FROM	kmd_catalog.kmd_index fk
WHERE	indrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.indrelid);
SELECT	ctid, inhrelid
FROM	kmd_catalog.kmd_inherits fk
WHERE	inhrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.inhrelid);
SELECT	ctid, inhparent
FROM	kmd_catalog.kmd_inherits fk
WHERE	inhparent != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.inhparent);
SELECT	ctid, classoid
FROM	kmd_catalog.kmd_init_privs fk
WHERE	classoid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.classoid);
SELECT	ctid, lanowner
FROM	kmd_catalog.kmd_language fk
WHERE	lanowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.lanowner);
SELECT	ctid, lanplcallfoid
FROM	kmd_catalog.kmd_language fk
WHERE	lanplcallfoid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.lanplcallfoid);
SELECT	ctid, laninline
FROM	kmd_catalog.kmd_language fk
WHERE	laninline != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.laninline);
SELECT	ctid, lanvalidator
FROM	kmd_catalog.kmd_language fk
WHERE	lanvalidator != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.lanvalidator);
SELECT	ctid, loid
FROM	kmd_catalog.kmd_largeobject fk
WHERE	loid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_largeobject_metadata pk WHERE pk.oid = fk.loid);
SELECT	ctid, lomowner
FROM	kmd_catalog.kmd_largeobject_metadata fk
WHERE	lomowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.lomowner);
SELECT	ctid, nspowner
FROM	kmd_catalog.kmd_namespace fk
WHERE	nspowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.nspowner);
SELECT	ctid, opcmethod
FROM	kmd_catalog.kmd_opclass fk
WHERE	opcmethod != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_am pk WHERE pk.oid = fk.opcmethod);
SELECT	ctid, opcnamespace
FROM	kmd_catalog.kmd_opclass fk
WHERE	opcnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.opcnamespace);
SELECT	ctid, opcowner
FROM	kmd_catalog.kmd_opclass fk
WHERE	opcowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.opcowner);
SELECT	ctid, opcfamily
FROM	kmd_catalog.kmd_opclass fk
WHERE	opcfamily != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_opfamily pk WHERE pk.oid = fk.opcfamily);
SELECT	ctid, opcintype
FROM	kmd_catalog.kmd_opclass fk
WHERE	opcintype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.opcintype);
SELECT	ctid, opckeytype
FROM	kmd_catalog.kmd_opclass fk
WHERE	opckeytype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.opckeytype);
SELECT	ctid, oprnamespace
FROM	kmd_catalog.kmd_operator fk
WHERE	oprnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.oprnamespace);
SELECT	ctid, oprowner
FROM	kmd_catalog.kmd_operator fk
WHERE	oprowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.oprowner);
SELECT	ctid, oprleft
FROM	kmd_catalog.kmd_operator fk
WHERE	oprleft != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.oprleft);
SELECT	ctid, oprright
FROM	kmd_catalog.kmd_operator fk
WHERE	oprright != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.oprright);
SELECT	ctid, oprresult
FROM	kmd_catalog.kmd_operator fk
WHERE	oprresult != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.oprresult);
SELECT	ctid, oprcom
FROM	kmd_catalog.kmd_operator fk
WHERE	oprcom != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.oprcom);
SELECT	ctid, oprnegate
FROM	kmd_catalog.kmd_operator fk
WHERE	oprnegate != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.oprnegate);
SELECT	ctid, oprcode
FROM	kmd_catalog.kmd_operator fk
WHERE	oprcode != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.oprcode);
SELECT	ctid, oprrest
FROM	kmd_catalog.kmd_operator fk
WHERE	oprrest != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.oprrest);
SELECT	ctid, oprjoin
FROM	kmd_catalog.kmd_operator fk
WHERE	oprjoin != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.oprjoin);
SELECT	ctid, opfmethod
FROM	kmd_catalog.kmd_opfamily fk
WHERE	opfmethod != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_am pk WHERE pk.oid = fk.opfmethod);
SELECT	ctid, opfnamespace
FROM	kmd_catalog.kmd_opfamily fk
WHERE	opfnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.opfnamespace);
SELECT	ctid, opfowner
FROM	kmd_catalog.kmd_opfamily fk
WHERE	opfowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.opfowner);
SELECT	ctid, partrelid
FROM	kmd_catalog.kmd_partitioned_table fk
WHERE	partrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.partrelid);
SELECT	ctid, partdefid
FROM	kmd_catalog.kmd_partitioned_table fk
WHERE	partdefid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.partdefid);
SELECT	ctid, polrelid
FROM	kmd_catalog.kmd_policy fk
WHERE	polrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.polrelid);
SELECT	ctid, pronamespace
FROM	kmd_catalog.kmd_proc fk
WHERE	pronamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.pronamespace);
SELECT	ctid, proowner
FROM	kmd_catalog.kmd_proc fk
WHERE	proowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.proowner);
SELECT	ctid, prolang
FROM	kmd_catalog.kmd_proc fk
WHERE	prolang != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_language pk WHERE pk.oid = fk.prolang);
SELECT	ctid, provariadic
FROM	kmd_catalog.kmd_proc fk
WHERE	provariadic != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.provariadic);
SELECT	ctid, prosupport
FROM	kmd_catalog.kmd_proc fk
WHERE	prosupport != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.prosupport);
SELECT	ctid, prorettype
FROM	kmd_catalog.kmd_proc fk
WHERE	prorettype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.prorettype);
SELECT	ctid, rngtypid
FROM	kmd_catalog.kmd_range fk
WHERE	rngtypid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.rngtypid);
SELECT	ctid, rngsubtype
FROM	kmd_catalog.kmd_range fk
WHERE	rngsubtype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.rngsubtype);
SELECT	ctid, rngcollation
FROM	kmd_catalog.kmd_range fk
WHERE	rngcollation != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_collation pk WHERE pk.oid = fk.rngcollation);
SELECT	ctid, rngsubopc
FROM	kmd_catalog.kmd_range fk
WHERE	rngsubopc != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_opclass pk WHERE pk.oid = fk.rngsubopc);
SELECT	ctid, rngcanonical
FROM	kmd_catalog.kmd_range fk
WHERE	rngcanonical != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.rngcanonical);
SELECT	ctid, rngsubdiff
FROM	kmd_catalog.kmd_range fk
WHERE	rngsubdiff != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.rngsubdiff);
SELECT	ctid, ev_class
FROM	kmd_catalog.kmd_rewrite fk
WHERE	ev_class != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.ev_class);
SELECT	ctid, seqrelid
FROM	kmd_catalog.kmd_sequence fk
WHERE	seqrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.seqrelid);
SELECT	ctid, seqtypid
FROM	kmd_catalog.kmd_sequence fk
WHERE	seqtypid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.seqtypid);
SELECT	ctid, refclassid
FROM	kmd_catalog.kmd_shdepend fk
WHERE	refclassid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.refclassid);
SELECT	ctid, classoid
FROM	kmd_catalog.kmd_shdescription fk
WHERE	classoid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.classoid);
SELECT	ctid, starelid
FROM	kmd_catalog.kmd_statistic fk
WHERE	starelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.starelid);
SELECT	ctid, staop1
FROM	kmd_catalog.kmd_statistic fk
WHERE	staop1 != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.staop1);
SELECT	ctid, staop2
FROM	kmd_catalog.kmd_statistic fk
WHERE	staop2 != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.staop2);
SELECT	ctid, staop3
FROM	kmd_catalog.kmd_statistic fk
WHERE	staop3 != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.staop3);
SELECT	ctid, staop4
FROM	kmd_catalog.kmd_statistic fk
WHERE	staop4 != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.staop4);
SELECT	ctid, staop5
FROM	kmd_catalog.kmd_statistic fk
WHERE	staop5 != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.staop5);
SELECT	ctid, stxrelid
FROM	kmd_catalog.kmd_statistic_ext fk
WHERE	stxrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.stxrelid);
SELECT	ctid, stxnamespace
FROM	kmd_catalog.kmd_statistic_ext fk
WHERE	stxnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.stxnamespace);
SELECT	ctid, stxowner
FROM	kmd_catalog.kmd_statistic_ext fk
WHERE	stxowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.stxowner);
SELECT	ctid, stxoid
FROM	kmd_catalog.kmd_statistic_ext_data fk
WHERE	stxoid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_statistic_ext pk WHERE pk.oid = fk.stxoid);
SELECT	ctid, spcowner
FROM	kmd_catalog.kmd_tablespace fk
WHERE	spcowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.spcowner);
SELECT	ctid, trftype
FROM	kmd_catalog.kmd_transform fk
WHERE	trftype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.trftype);
SELECT	ctid, trflang
FROM	kmd_catalog.kmd_transform fk
WHERE	trflang != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_language pk WHERE pk.oid = fk.trflang);
SELECT	ctid, trffromsql
FROM	kmd_catalog.kmd_transform fk
WHERE	trffromsql != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.trffromsql);
SELECT	ctid, trftosql
FROM	kmd_catalog.kmd_transform fk
WHERE	trftosql != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.trftosql);
SELECT	ctid, tgrelid
FROM	kmd_catalog.kmd_trigger fk
WHERE	tgrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.tgrelid);
SELECT	ctid, tgfoid
FROM	kmd_catalog.kmd_trigger fk
WHERE	tgfoid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.tgfoid);
SELECT	ctid, tgconstrrelid
FROM	kmd_catalog.kmd_trigger fk
WHERE	tgconstrrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.tgconstrrelid);
SELECT	ctid, tgconstrindid
FROM	kmd_catalog.kmd_trigger fk
WHERE	tgconstrindid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.tgconstrindid);
SELECT	ctid, tgconstraint
FROM	kmd_catalog.kmd_trigger fk
WHERE	tgconstraint != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_constraint pk WHERE pk.oid = fk.tgconstraint);
SELECT	ctid, cfgnamespace
FROM	kmd_catalog.kmd_ts_config fk
WHERE	cfgnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.cfgnamespace);
SELECT	ctid, cfgowner
FROM	kmd_catalog.kmd_ts_config fk
WHERE	cfgowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.cfgowner);
SELECT	ctid, cfgparser
FROM	kmd_catalog.kmd_ts_config fk
WHERE	cfgparser != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_ts_parser pk WHERE pk.oid = fk.cfgparser);
SELECT	ctid, mapcfg
FROM	kmd_catalog.kmd_ts_config_map fk
WHERE	mapcfg != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_ts_config pk WHERE pk.oid = fk.mapcfg);
SELECT	ctid, mapdict
FROM	kmd_catalog.kmd_ts_config_map fk
WHERE	mapdict != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_ts_dict pk WHERE pk.oid = fk.mapdict);
SELECT	ctid, dictnamespace
FROM	kmd_catalog.kmd_ts_dict fk
WHERE	dictnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.dictnamespace);
SELECT	ctid, dictowner
FROM	kmd_catalog.kmd_ts_dict fk
WHERE	dictowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.dictowner);
SELECT	ctid, dicttemplate
FROM	kmd_catalog.kmd_ts_dict fk
WHERE	dicttemplate != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_ts_template pk WHERE pk.oid = fk.dicttemplate);
SELECT	ctid, prsnamespace
FROM	kmd_catalog.kmd_ts_parser fk
WHERE	prsnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.prsnamespace);
SELECT	ctid, prsstart
FROM	kmd_catalog.kmd_ts_parser fk
WHERE	prsstart != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.prsstart);
SELECT	ctid, prstoken
FROM	kmd_catalog.kmd_ts_parser fk
WHERE	prstoken != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.prstoken);
SELECT	ctid, prsend
FROM	kmd_catalog.kmd_ts_parser fk
WHERE	prsend != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.prsend);
SELECT	ctid, prsheadline
FROM	kmd_catalog.kmd_ts_parser fk
WHERE	prsheadline != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.prsheadline);
SELECT	ctid, prslextype
FROM	kmd_catalog.kmd_ts_parser fk
WHERE	prslextype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.prslextype);
SELECT	ctid, tmplnamespace
FROM	kmd_catalog.kmd_ts_template fk
WHERE	tmplnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.tmplnamespace);
SELECT	ctid, tmplinit
FROM	kmd_catalog.kmd_ts_template fk
WHERE	tmplinit != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.tmplinit);
SELECT	ctid, tmpllexize
FROM	kmd_catalog.kmd_ts_template fk
WHERE	tmpllexize != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.tmpllexize);
SELECT	ctid, typnamespace
FROM	kmd_catalog.kmd_type fk
WHERE	typnamespace != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_namespace pk WHERE pk.oid = fk.typnamespace);
SELECT	ctid, typowner
FROM	kmd_catalog.kmd_type fk
WHERE	typowner != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_authid pk WHERE pk.oid = fk.typowner);
SELECT	ctid, typrelid
FROM	kmd_catalog.kmd_type fk
WHERE	typrelid != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_class pk WHERE pk.oid = fk.typrelid);
SELECT	ctid, typelem
FROM	kmd_catalog.kmd_type fk
WHERE	typelem != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.typelem);
SELECT	ctid, typarray
FROM	kmd_catalog.kmd_type fk
WHERE	typarray != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.typarray);
SELECT	ctid, typinput
FROM	kmd_catalog.kmd_type fk
WHERE	typinput != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.typinput);
SELECT	ctid, typoutput
FROM	kmd_catalog.kmd_type fk
WHERE	typoutput != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.typoutput);
SELECT	ctid, typreceive
FROM	kmd_catalog.kmd_type fk
WHERE	typreceive != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.typreceive);
SELECT	ctid, typsend
FROM	kmd_catalog.kmd_type fk
WHERE	typsend != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.typsend);
SELECT	ctid, typmodin
FROM	kmd_catalog.kmd_type fk
WHERE	typmodin != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.typmodin);
SELECT	ctid, typmodout
FROM	kmd_catalog.kmd_type fk
WHERE	typmodout != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.typmodout);
SELECT	ctid, typanalyze
FROM	kmd_catalog.kmd_type fk
WHERE	typanalyze != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_proc pk WHERE pk.oid = fk.typanalyze);
SELECT	ctid, typbasetype
FROM	kmd_catalog.kmd_type fk
WHERE	typbasetype != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.typbasetype);
SELECT	ctid, typcollation
FROM	kmd_catalog.kmd_type fk
WHERE	typcollation != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_collation pk WHERE pk.oid = fk.typcollation);
SELECT	ctid, conpfeqop
FROM	(SELECT ctid, unnest(conpfeqop) AS conpfeqop FROM kmd_catalog.kmd_constraint) fk
WHERE	conpfeqop != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.conpfeqop);
SELECT	ctid, conppeqop
FROM	(SELECT ctid, unnest(conppeqop) AS conppeqop FROM kmd_catalog.kmd_constraint) fk
WHERE	conppeqop != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.conppeqop);
SELECT	ctid, conffeqop
FROM	(SELECT ctid, unnest(conffeqop) AS conffeqop FROM kmd_catalog.kmd_constraint) fk
WHERE	conffeqop != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.conffeqop);
SELECT	ctid, conexclop
FROM	(SELECT ctid, unnest(conexclop) AS conexclop FROM kmd_catalog.kmd_constraint) fk
WHERE	conexclop != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_operator pk WHERE pk.oid = fk.conexclop);
SELECT	ctid, proallargtypes
FROM	(SELECT ctid, unnest(proallargtypes) AS proallargtypes FROM kmd_catalog.kmd_proc) fk
WHERE	proallargtypes != 0 AND
	NOT EXISTS(SELECT 1 FROM kmd_catalog.kmd_type pk WHERE pk.oid = fk.proallargtypes);
