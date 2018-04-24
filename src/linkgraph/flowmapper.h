/* $Id$ */

/*
* This file is part of OpenTTD.
* OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
* OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
*/

/** @file flowmapper.h Declaration of flow mapper; maps paths into flows at nodes. */

#ifndef FLOWMAPPER_H_
#define FLOWMAPPER_H_

#include "linkgraphjob_base.h"

/**
* Map the path trees generated by the MCF solver into flows. The path tree is
* useful to cache capacities and distances and allow quick disconnecting and
* reconnecting to other paths. The flows show how much cargo from which nodes
* is to be routed in which direction at a given node. This is what we need in
* the end.
*/
class FlowMapper : public ComponentHandler {
public:

	/**
	* Create a flow mapper.
	* @param scale Whether the flow mapper should scale all flows to monthly
	*              values. Only do that on the very last flow mapping.
	*/
	FlowMapper(bool scale) : scale(scale) {}
	virtual void Run(LinkGraphJob &job) const;

	/**
	* Virtual destructor has to be defined because of virtual Run().
	*/
	virtual ~FlowMapper() {}
private:

	/**
	* Whether the flow mapper should scale all flows to monthly values.
	*/
	const bool scale;
};

#endif /* FLOWMAPPER_H_ */