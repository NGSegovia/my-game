# GdUnit generated TestSuite
class_name ballTest
extends GdUnitTestSuite

# TestSuite generated from
const __source = 'res://logic/ball.gd'

var _test_data :ball

func before_test():
   _test_data = ball.new()

func test_reset() -> void:
	# Given a ball instance
	
	# WHEN reset is invoked
	_test_data.reset()
	
	# THEN speed is set to default
	assert_int(ball.DEFAULT_SPEED).is_equal(_test_data._speed)
