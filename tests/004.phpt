--TEST--
Check for interned_strings() on NTS
--SKIPIF--
<?php
    if (!extension_loaded("strdumper")) print "skip";
    if (version_compare(PHP_VERSION, '5.2.7') >= 0 && PHP_ZTS) print "skip";
--FILE--
<?php
$interned = interned_strings();
var_dump(in_array("var_dump", $interned));
--EXPECT--
bool(true)
