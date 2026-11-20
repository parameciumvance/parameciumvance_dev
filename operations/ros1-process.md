# ROS1 程序中斷與結束

歷史筆記：NodeHandle 初始化相關流程會註冊 SIGINT 處理，呼叫 ros::shutdown，使 ros::ok() 為 false，程式仍須自行結束迴圈與清理；非 NodeHandle 本身必然註冊，依 ros::init 選項。SIGTERM 預設不由同一 handler 處理。舊觀察 roslaunch 處理 SIGINT、SIGTERM、SIGHUP 並向 node 發 SIGINT，後續可能升級終止訊號；依版本確認。

系統關機可能直接送 SIGTERM，硬體驅動可能需自行處理安全關閉；舊參考版本 rplidar_ros1001.0.1、rpi_rover0.2.2（未驗證）。測試各訊號、資源清理、超時與恢復，勿在 signal handler 直接進行不安全操作。

- [ROS1](../robotics/ros1/README.md)
- [日誌](logging/ros1-logging.md)
