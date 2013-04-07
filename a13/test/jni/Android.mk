LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS := -g

LOCAL_MODULE    := hello-ndk
LOCAL_SRC_FILES := hello-ndk.c

include  $(BUILD_EXECUTABLE)
