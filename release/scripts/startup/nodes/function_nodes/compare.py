import bpy
from bpy.props import *
from .. base import FunctionNode
from .. socket_builder import SocketBuilder

operation_items = [
    ("LESS_THAN", "Less Than", "A < B", "", 1),
]

class CompareNode(bpy.types.Node, FunctionNode):
    bl_idname = "fn_CompareNode"
    bl_label = "Compare"

    search_terms = (
        ("Less Than", {"operation" : "LESS_THAN"}),
    )

    operation: EnumProperty(
        name="Operation",
        items=operation_items,
        update=FunctionNode.refresh,
    )

    use_list__a: SocketBuilder.VectorizedProperty()
    use_list__b: SocketBuilder.VectorizedProperty()

    def declaration(self, builder: SocketBuilder):
        builder.vectorized_input(
            "a", "use_list__a",
            "A", "A", "Float")
        builder.vectorized_input(
            "b", "use_list__b",
            "B", "B", "Float")

        builder.vectorized_output(
            "result", ["use_list__a", "use_list__b"],
            "Result", "Result", "Boolean")

    def draw(self, layout):
        layout.prop(self, "operation", text="")
