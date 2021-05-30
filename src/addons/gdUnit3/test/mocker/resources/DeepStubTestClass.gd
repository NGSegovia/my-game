class_name DeepStubTestClass
	
class XShape:
	var _shape : Shape = Shape.new()

	func get_shape() -> Shape:
		return _shape


var _shape :XShape
	
func add(shape :XShape):
	_shape = shape

func validate() -> bool: 
	return _shape.get_shape().get_margin() == 0.0
