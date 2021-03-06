<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Extension\Properties;

use PHPUnit\Framework\TestCase;
use Test\Properties\PropertyArray;

class PropertyArrayTest extends TestCase
{
    public function testAssertations()
    {
        $t = new PropertyArray();
        $this->assertSame([1], $t->someArray);
    }
}
