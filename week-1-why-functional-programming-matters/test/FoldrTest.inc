<?php

require_once(join(DIRECTORY_SEPARATOR, array(dirname(dirname(__FILE__)), 'foldr.inc')));

class FoldrTest extends PHPUnit_Framework_TestCase
{

  /**
   * @test
   */
  public function sum()
  {
    $add = function($a, $b)
      {
        return $a + $b;
      };
    $this->assertEquals(0, $add(0,0));
    $this->assertEquals(1, $add(1, 0));

    $sum = function($lst) use ($add)
      {
        $fn = foldr($add, 0);
        return $fn($lst);
      };

    $this->assertEquals(0, $sum(array()));
    $this->assertEquals(0, $sum(array(0)));
    $this->assertEquals(1, $sum(array(1)));
    $this->assertEquals(2, $sum(array(1,1)));
    $this->assertEquals(4, $sum(array(1,3)));
  }

  /**
   * @test
   */
  public function product()
  {
    $prod = function($a, $b)
      {
        return $a * $b;
      };

    $product = function($lst) use ($prod)
      {
        $fn = foldr($prod, 1);
        return $fn($lst);
      };

    $this->assertEquals(1, $product(array()));
    $this->assertEquals(0, $product(array(0)));
    $this->assertEquals(1, $product(array(1)));
    $this->assertEquals(6, $product(array(1,2,3)));
  }


  /**
   * @test
   */
  public function anytrue()
  {
    $or = function($a, $b)
      {
        return $a || $b;
      };

    $anytrue = function($lst) use ($or)
      {
        $fn = foldr($or, false);
        return $fn($lst);
      };

    $this->assertEquals(false, $anytrue(array()));
    $this->assertEquals(true, $anytrue(array(true)));
    $this->assertEquals(false, $anytrue(array(false)));
    $this->assertEquals(true, $anytrue(array(false, true)));
    $this->assertEquals(true, $anytrue(array(true, true)));
    $this->assertEquals(false, $anytrue(array(false, false, false)));
  }

  /**
   * @test
   */
  public function alltrue()
  {
    $and = function($a, $b)
      {
        return $a && $b;
      };

    $alltrue = function($lst) use ($and)
      {
        $fn = foldr($and, true);
        return $fn($lst);
      };

    $this->assertEquals(true, $alltrue(array()));
    $this->assertEquals(true, $alltrue(array(true)));
    $this->assertEquals(false, $alltrue(array(false)));
    $this->assertEquals(false, $alltrue(array(false, true)));
    $this->assertEquals(true, $alltrue(array(true, true)));
    $this->assertEquals(false, $alltrue(array(false, false, false)));
    $this->assertEquals(false, $alltrue(array(false, true, false)));
  }


  /**
   * @test
   */
  public function append()
  {
    $cons = function($a, $b)
      {
        return cons($a, $b);
      };

    $append = function($a, $b) use ($cons)
      {
        $fn = foldr($cons, $b);
        return $fn($a);
      };

    $this->assertEquals(array(1,2,3,4), $append(array(1,2), array(3,4)));
  }

  /**
   * @test
   */
  public function length()
  {
    $count = function($a, $b)
      {
        return $b + 1;
      };

    $length = function($lst) use ($count)
      {
        $fn = foldr($count, 0);
        return $fn($lst);
      };

    $this->assertEquals(0, $length(array()));
    $this->assertEquals(1, $length(array(1)));
    $this->assertEquals(2, $length(array(1, 2)));
    $this->assertEquals(5, $length(array(1, 2, 3, 4, 5)));
  }

}
