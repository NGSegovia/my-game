class_name GeneratedPersonTest
extends GdUnitTestSuite

# TestSuite generated from",
const __source = "res://addons/gdUnit3/test/resources/core/Person.gd"

func test_name():
	assert_that(Person.new().name()).is_equal("Hoschi")
