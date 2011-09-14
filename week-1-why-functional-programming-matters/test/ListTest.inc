<?php

require_once('list.inc');

class ListTest extends PHPUnit_Framework_TestCase
{

  /**
   * @test
   */
  public function first_should_return_empty_array_for_empty_array()
  {
    $ary = array();
    $this->assertEquals(array(), first($ary));
  }

  /**
   * @test
   */
  public function first_should_return_first_element_of_single_element_array()
  {
    $ary = array(1);
    $this->assertEquals(1, first($ary));
  }

  /**
   * @test
   */
  public function first_should_return_first_element_of_array()
  {
    $ary = array(1, 2, 3);
    $this->assertEquals(1, first($ary));
  }

  /**
   * @test
   */
  public function rest_should_return_empty_array_for_empty_array()
  {
    $this->assertEquals(array(), rest(array()));
  }

  /**
   * @test
   */
  public function rest_should_return_empty_array_for_single_element_array()
  {
    $this->assertEquals(array(), rest(array(1)));
  }

  /**
   * @test
   */
  public function rest_should_return_expected_array_for_array()
  {
    $this->assertEquals(array(2,3), rest(array(1,2,3)));
  }

  /**
   * @test
   */
  public function cons_of_empty_array()
  {
    $this->assertEquals(array(1), cons(1, array()));
  }

  /**
   * @test
   */
  public function cons_of_non_empty_array()
  {
    $this->assertEquals(array(1,2,3), cons(1, array(2,3)));
  }

}
