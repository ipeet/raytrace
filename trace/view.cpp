/******************************************************************************
* view.cpp
* Copyright 2010 Iain Peet
*
* Provides RayView classes, which trace a number of rays to render an image.
* Also provides the ViewObjectList class, which maintains a list of objects
* which might be seen in a RayView.
******************************************************************************
* This program is distrib
    $(COMMON_OBJS) \uted under the of the GNU Lesser Public License. 
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*****************************************************************************/

#include <vector>

#include "view.h"

#include "image/rayImage.h"
#include "util/trace.h"
#include "geom.h"
#include "ray.h"
#include "object.h"
#include "world.h"

using std::vector;

static trc_ctl_t viewTrace = {
    TRC_DFL_LVL,
    "VIEW",
    TRC_STDOUT
};
#define TRACE(level,args...) \
    trc_printf(&viewTrace,level,1,args)

//! Render the given image using the given object list
void ParallelView::render(RayImage &image, World &world, int depth)
{
    char trcbuf[36];  // for trace messages
    
    RayVector viewDir = m_xVec.cross(m_yVec).unitify();

    TRACE(TRC_STAT,"Beginning ParallelView render.\n");
    TRACE(TRC_STAT,"Image size: %d x %d\n",image.width(),image.height());
    TRACE(TRC_STAT,"Origin: %s\n",m_origin.snprint(trcbuf,36));
    TRACE(TRC_STAT,"xVec: %s\n",m_xVec.snprint(trcbuf,36));
    TRACE(TRC_STAT,"yVec: %s\n",m_yVec.snprint(trcbuf,36));
    TRACE(TRC_STAT,"Ray direction: %s\n",viewDir.snprint(trcbuf,36));

    /* Render the image */
    // The proportion of the width vector that is the distance from one pixel 
    // to the next
    double pixStepX = 1.0/image.width();
    double pixStepY = 1.0/image.height();
    for(unsigned i=0; i<image.height(); i+=1) {
        for(unsigned j=0; j<image.width(); j+=1) {
            double xDist =
                pixStepX/2.0 // middle of pixel
                + pixStepX*j; // which pixel
            double yDist = 
                pixStepY/2.0 
                + pixStepY*i;
            
            image.at(i,j).m_dir = viewDir;
            image.at(i,j).m_endpoint = m_origin + xDist*m_xVec + yDist*m_yVec;
            image.at(i,j).m_depthLimit = depth;

            TRACE(TRC_INFO,"Pixel endpoint: %s\n",
                  image.at(i,j).m_endpoint.snprint(trcbuf,36));

            world.trace(image.at(i,j));

            TRACE(TRC_INFO,"Render [%d,%d]: %s\n",
                  i,j,image.at(i,j).m_colour.snprint(trcbuf,32));
        }
    }
}

void AngleView::render(RayImage &image, World &object, int depth)
{
    #warning todo: implement
}

