#
# 1. Set the path and clear environment
# 	TARGET_PATH := $(call my-dir)
# 	include $(ENV_CLEAR)
#
# 2. Set the source files and headers files
#	TARGET_SRC := xxx_1.c xxx_2.c
#	TARGET_INc := xxx_1.h xxx_2.h
#
# 3. Set the output target
#	TARGET_MODULE := xxx
#
# 4. Include the main makefile
#	include $(BUILD_BIN)
#
# Before include the build makefile, you can set the compilaion
# flags, e.g. TARGET_ASFLAGS TARGET_CFLAGS TARGET_CPPFLAGS
#

LOCAL_PATH:= $(call my-dir)

#########################################
include $(CLEAR_VARS)
SRC_HEADERS:=  \

LOCAL_SRC_FILES := ff_user.c 
LOCAL_MODULE_TAGS := eng
LOCAL_MODULE := libFatFs
LOCAL_C_INCLUDES := \

LOCAL_SHARED_LIBRARIES := \
	libutils \


include $(BUILD_SHARED_LIBRARY)

