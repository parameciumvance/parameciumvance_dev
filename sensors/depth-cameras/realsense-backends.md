# RealSense 原始碼研究：後端與裝置列舉

舊 realsense_ros／librealsense 研究筆記，版本未記錄；以實際 checkout 的 CMake/[OS]_config.cmake 與建置旗標為準。

| 平台 | 歷史觀察 |
| --- | --- |
| Windows 7 | WINUSB_UVC_BACKEND（win7.win.winusb.rsusb-backend.hid.uvc） |
| 其他 Windows | WMF_BACKEND（mf.win.winusb） |
| Apple | LIBUVC_BACKEND（libuvc.libusb.rsusb-backend.hid.uvc） |
| 其他 Unix | V4L2_BACKEND（linux.libusb） |
| Android | RS2_USE_ANDROID_BACKEND（android.usbhost.rsusb-backend.hid.uvc） |

舊筆記稱 Win7 的 cmake=6.1，應理解為 Windows 系統版本值 6.1，而非 CMake 工具版本，待核對。APT 安裝版本曾觀察到 rsusb-backend，參考 https://github.com/IntelRealSense/realsense-ros/issues/1515 ，不能推論所有套件均如此。

## V4L2 裝置列舉

舊研究記錄 devices 分 UVC、USB、HID，再以 pick_ds5_devices 選出 D400 系列；UVC 搜尋 /sys/class/video4linux，HID 搜尋 /sys/bus/iio/devices，USB 透過 libusb_get_device_list。context、sensors 在原筆記僅有標題，未有進一步結論。

來源：TOOLS_NOTE/週邊裝置/realsense（Git 歷史）。
