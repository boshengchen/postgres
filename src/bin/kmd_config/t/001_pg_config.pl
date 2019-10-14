use strict;
use warnings;
use TestLib;
use Test::More tests => 20;

program_help_ok('kmd_config');
program_version_ok('kmd_config');
program_options_handling_ok('kmd_config');
command_like([ 'kmd_config', '--bindir' ], qr/bin/, 'kmd_config single option')
  ;    # XXX might be wrong
command_like([ 'kmd_config', '--bindir', '--libdir' ],
	qr/bin.*\n.*lib/, 'kmd_config two options');
command_like([ 'kmd_config', '--libdir', '--bindir' ],
	qr/lib.*\n.*bin/, 'kmd_config two options different order');
command_like(['kmd_config'], qr/.*\n.*\n.*/,
	'kmd_config without options prints many lines');
