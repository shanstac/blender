/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2005 Blender Foundation.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

#include "../node_shader_util.h"

/* **************** OUTPUT ******************** */

static bNodeSocketTemplate sh_node_aov_output_in[] = {
	{	SOCK_RGBA,  1, N_("Color"),	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
	{	SOCK_FLOAT, 1, N_("Value"),	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
	{	-1, 0, ""	}
};

static void node_shader_init_aov_output(bNodeTree *UNUSED(ntree), bNode *node)
{
	NodeShaderAOVOutput *aov = MEM_callocN(sizeof(NodeShaderAOVOutput), "NodeShaderAOVOutput");
	node->storage = aov;
}

/* node type definition */
void register_node_type_sh_aov_output(void)
{
	static bNodeType ntype;

	sh_node_type_base(&ntype, SH_NODE_AOV_OUTPUT, "AOV Output", NODE_CLASS_OUTPUT, 0);
	node_type_compatibility(&ntype, NODE_NEW_SHADING);
	node_type_socket_templates(&ntype, sh_node_aov_output_in, NULL);
	node_type_init(&ntype, node_shader_init_aov_output);
	node_type_storage(&ntype, "NodeShaderAOVOutput", node_free_standard_storage, node_copy_standard_storage);

	nodeRegisterType(&ntype);
}
