/******************************************************************************
 * transform.h
 * Copyright 2011 Iain Peet
 *
 * Defines an abstract class for all operations which transform an image.
 ******************************************************************************
 * This program is distributed under the of the GNU Lesser Public License. 
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

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

class Image;

class ImageTransform {
public:
    virtual ~ImageTransform() {}

    /* Applies this transform to the given image.
     * @return the given image, transformed. */
    virtual Image& apply(Image& img) = 0;
};

#endif //TRAMSFORM_H_
