#
# Copyright (C) 2012 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Base modules (will move elsewhere, previously user tagged)
$(call inherit-product, $(SRC_TARGET_DIR)/product/external.mk) 

$(call inherit-product, $(SRC_TARGET_DIR)/product/external.mk) 

PRODUCT_PACKAGES += \
	libcamera_client \
    libcameraservice \
    libcamera_metadata \
	libvdecoder \
	libvencoder \
	libVE \
	libMemAdapter \
	libaw_audio \
	libaw_audioa \
	libstagefright_soft_cedar_h264dec \
	libfacedetection \
	libcedarxstream \
	libthirdpartstream \
	libcedarxsftstream \
	libsunxi_alloc \
	libsrec_jni \
	libjpgenc \
	libstagefrighthw \
	libOmxCore \
	libOmxVdec \
	libOmxVenc \
	libaw_h264enc \
	libI420colorconvert \
	libsunxi_alloc \
	libmedia \
    libmedia_proxy \
	libvideoresizer \
    libmediaplayerservice \
    libaudioflinger \
    mediaserver \
    camera.sun5i \
    libawmd \
    libjpeg \

#    libdownmix \
#    libbundlewrapper \
#    libswdrm \
