# ROS1 資料與節點整合

歷史筆記整理，未重新驗證。

## 動態調參

C++ Client setConfiguration 舊案例為整份配置，Python update_configuration 可傳指定參數；須依 API 版本確認。生成標頭依賴見 [catkin](../../development/build/ros1-catkin-legacy.md)。

## 影像資料

Python cv_bridge.cv2_to_imgmsg 若為 BGR 影像應明確指定 encoding='bgr8'；passthrough 保留資料型別，不一定傳達色彩語意。舊筆記參考 sensor_msgs/image_encodings.h；接收端若假定可自動轉換可能失敗。明確指定實際編碼，不將所有影像一律標成 bgr8。

## API 變更

舊錯誤 `expected constructor, destructor, or type conversion before ‘(’ token`，涉及 `PLUGINLIB_DECLARE_CLASS(navfn, NavfnROS, navfn::NavfnROS, nav_core::BaseGlobalPlanner)`；檢查 pluginlib 版本與替代匯出巨集，不直接認定唯一原因。

## 時間與座標

多機 stamp 不完全同步：2022-08-05 UWB 無法設置站點的歷史案例。參見 [時間同步](../../operations/time-synchronization.md)。RViz `Failed to transform from frame [/map]` 舊筆記指 Noetic 使用 tf2 時 frame ID 不允許前導斜線；檢查 frame ID、TF tree 與時間，不應一律歸因於斜線。待研究：負時間 Duration::sleep 似乎 block，但原始碼觀察不一致。

## 多 launch 與參數管理

先獨立啟動 roscore，其他 roslaunch 用 --wait 等待，避免 core 位置不明或衝突（`run_id on parameter server does not match declared run_id`）；確認 ROS_MASTER_URI。參數盡量由自己的配置或受控 launch 管理，避免上游檔案不預期變更。RLException: Roslaunch got a 'No such file or directory' error while attempting to run：Ubuntu20 升級後缺 /usr/bin/python 是舊案例可能原因，亦應檢查其他 executable/shebang。
