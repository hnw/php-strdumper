--TEST--
Check for interned_strings() on ZTS
--SKIPIF--
<?php
    if (!extension_loaded("strdumper")) print "skip";
    if (version_compare(PHP_VERSION, '5.2.7') >= 0 && !PHP_ZTS) print "skip";
--FILE--
<?php
$interned = interned_strings();
var_dump($interned == array());
--EXPECT--
bool(true)
