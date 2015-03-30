
```
2009/08/04 15:59:36 [debug] 16046#0: bind() 0.0.0.0:81 #6 
2009/08/04 15:59:36 [notice] 16046#0: using the "epoll" event method
2009/08/04 15:59:36 [debug] 16046#0: counter: B7FAA080, 1
2009/08/04 15:59:36 [notice] 16046#0: nginx/0.7.61
2009/08/04 15:59:36 [notice] 16046#0: built by gcc 4.2.4 (Ubuntu 4.2.4-1ubuntu4)
2009/08/04 15:59:36 [notice] 16046#0: OS: Linux 2.6.24-24-generic
2009/08/04 15:59:36 [notice] 16046#0: getrlimit(RLIMIT_NOFILE): 1024:1024
2009/08/04 15:59:36 [debug] 16083#0: write: 7, BF9D7EF6, 6, 0
2009/08/04 15:59:36 [debug] 16083#0: setproctitle: "nginx: master process ./nginx"
2009/08/04 15:59:36 [notice] 16083#0: start worker processes
2009/08/04 15:59:36 [debug] 16083#0: channel 7:8
2009/08/04 15:59:36 [debug] 16084#0: malloc: 080C3B98:6144
2009/08/04 15:59:36 [debug] 16084#0: malloc: 080D1BC0:94208
2009/08/04 15:59:36 [debug] 16084#0: malloc: 080E8BC8:53248
2009/08/04 15:59:36 [debug] 16084#0: malloc: 080F5BD0:53248
2009/08/04 15:59:36 [debug] 16084#0: epoll add event: fd:8 op:1 ev:00000001
2009/08/04 15:59:36 [debug] 16084#0: setproctitle: "nginx: worker process"
2009/08/04 15:59:36 [debug] 16084#0: worker cycle
2009/08/04 15:59:36 [debug] 16084#0: accept mutex locked
2009/08/04 15:59:36 [debug] 16084#0: epoll add event: fd:6 op:1 ev:00000001
2009/08/04 15:59:36 [debug] 16084#0: epoll timer: -1
2009/08/04 15:59:36 [notice] 16083#0: start worker process 16084
2009/08/04 15:59:36 [debug] 16083#0: channel 9:10
2009/08/04 15:59:36 [debug] 16085#0: malloc: 080C3B98:6144
2009/08/04 15:59:36 [debug] 16085#0: malloc: 080D1BC0:94208
2009/08/04 15:59:36 [debug] 16085#0: malloc: 080E8BC8:53248
2009/08/04 15:59:36 [debug] 16085#0: malloc: 080F5BD0:53248
2009/08/04 15:59:36 [debug] 16085#0: epoll add event: fd:10 op:1 ev:00000001
2009/08/04 15:59:36 [debug] 16085#0: setproctitle: "nginx: worker process"
2009/08/04 15:59:36 [debug] 16085#0: worker cycle
2009/08/04 15:59:36 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:36 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:36 [notice] 16083#0: start worker process 16085
2009/08/04 15:59:36 [debug] 16083#0: pass channel s:1 pid:16085 fd:9 to s:0 pid:16084 fd:7
2009/08/04 15:59:36 [debug] 16084#0: epoll: fd:8 ev:0001 d:080D1C1C
2009/08/04 15:59:36 [debug] 16084#0: post event 080E8BFC
2009/08/04 15:59:36 [debug] 16084#0: timer delta: 44
2009/08/04 15:59:36 [debug] 16084#0: posted events 080E8BFC
2009/08/04 15:59:36 [debug] 16084#0: posted event 080E8BFC
2009/08/04 15:59:36 [debug] 16084#0: delete posted event 080E8BFC
2009/08/04 15:59:36 [debug] 16084#0: channel handler
2009/08/04 15:59:36 [debug] 16084#0: channel: 16
2009/08/04 15:59:36 [debug] 16084#0: channel command: 1
2009/08/04 15:59:36 [debug] 16084#0: get channel s:1 pid:16085 fd:7
2009/08/04 15:59:36 [debug] 16084#0: channel: -2
2009/08/04 15:59:36 [debug] 16084#0: posted event 00000000
2009/08/04 15:59:36 [debug] 16084#0: worker cycle
2009/08/04 15:59:36 [debug] 16084#0: accept mutex locked
2009/08/04 15:59:36 [debug] 16084#0: epoll timer: -1
2009/08/04 15:59:36 [debug] 16083#0: sigsuspend
2009/08/04 15:59:37 [debug] 16085#0: timer delta: 542
2009/08/04 15:59:37 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:37 [debug] 16085#0: worker cycle
2009/08/04 15:59:37 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:37 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:37 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:37 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:37 [debug] 16085#0: worker cycle
2009/08/04 15:59:37 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:37 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:38 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:38 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:38 [debug] 16085#0: worker cycle
2009/08/04 15:59:38 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:38 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:38 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:38 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:38 [debug] 16085#0: worker cycle
2009/08/04 15:59:38 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:38 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:39 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:39 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:39 [debug] 16085#0: worker cycle
2009/08/04 15:59:39 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:39 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:39 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:39 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:39 [debug] 16085#0: worker cycle
2009/08/04 15:59:39 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:39 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:40 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:40 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:40 [debug] 16085#0: worker cycle
2009/08/04 15:59:40 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:40 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:40 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:40 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:40 [debug] 16085#0: worker cycle
2009/08/04 15:59:40 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:40 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:41 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:41 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:41 [debug] 16085#0: worker cycle
2009/08/04 15:59:41 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:41 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:41 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:41 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:41 [debug] 16085#0: worker cycle
2009/08/04 15:59:41 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:41 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:42 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:42 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:42 [debug] 16085#0: worker cycle
2009/08/04 15:59:42 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:42 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:42 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:42 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:42 [debug] 16085#0: worker cycle
2009/08/04 15:59:42 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:42 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:43 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:43 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:43 [debug] 16085#0: worker cycle
2009/08/04 15:59:43 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:43 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:43 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:43 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:43 [debug] 16085#0: worker cycle
2009/08/04 15:59:43 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:43 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:44 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:44 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:44 [debug] 16085#0: worker cycle
2009/08/04 15:59:44 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:44 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:44 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:44 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:44 [debug] 16085#0: worker cycle
2009/08/04 15:59:44 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:44 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:45 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:45 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:45 [debug] 16085#0: worker cycle
2009/08/04 15:59:45 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:45 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:45 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:45 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:45 [debug] 16085#0: worker cycle
2009/08/04 15:59:45 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:45 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:46 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:46 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:46 [debug] 16085#0: worker cycle
2009/08/04 15:59:46 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:46 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:46 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:46 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:46 [debug] 16085#0: worker cycle
2009/08/04 15:59:46 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:46 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:47 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:47 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:47 [debug] 16085#0: worker cycle
2009/08/04 15:59:47 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:47 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:47 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:47 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:47 [debug] 16085#0: worker cycle
2009/08/04 15:59:47 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:47 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:48 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:48 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:48 [debug] 16085#0: worker cycle
2009/08/04 15:59:48 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:48 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:48 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:48 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:48 [debug] 16085#0: worker cycle
2009/08/04 15:59:48 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:48 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:49 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:49 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:49 [debug] 16085#0: worker cycle
2009/08/04 15:59:49 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:49 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:49 [debug] 16085#0: timer delta: 501
2009/08/04 15:59:49 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:49 [debug] 16085#0: worker cycle
2009/08/04 15:59:49 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:49 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:50 [debug] 16085#0: timer delta: 499
2009/08/04 15:59:50 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:50 [debug] 16085#0: worker cycle
2009/08/04 15:59:50 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:50 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:50 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:50 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:50 [debug] 16085#0: worker cycle
2009/08/04 15:59:50 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:50 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:51 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:51 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:51 [debug] 16085#0: worker cycle
2009/08/04 15:59:51 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:51 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:51 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:51 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:51 [debug] 16085#0: worker cycle
2009/08/04 15:59:51 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:51 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:52 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:52 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:52 [debug] 16085#0: worker cycle
2009/08/04 15:59:52 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:52 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:52 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:52 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:52 [debug] 16085#0: worker cycle
2009/08/04 15:59:52 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:52 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:53 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:53 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:53 [debug] 16085#0: worker cycle
2009/08/04 15:59:53 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:53 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:53 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:53 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:53 [debug] 16085#0: worker cycle
2009/08/04 15:59:53 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:53 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:54 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:54 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:54 [debug] 16085#0: worker cycle
2009/08/04 15:59:54 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:54 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:54 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:54 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:54 [debug] 16085#0: worker cycle
2009/08/04 15:59:54 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:54 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:55 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:55 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:55 [debug] 16085#0: worker cycle
2009/08/04 15:59:55 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:55 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:55 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:55 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:55 [debug] 16085#0: worker cycle
2009/08/04 15:59:55 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:55 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:56 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:56 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:56 [debug] 16085#0: worker cycle
2009/08/04 15:59:56 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:56 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:56 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:56 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:56 [debug] 16085#0: worker cycle
2009/08/04 15:59:56 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:56 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:57 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:57 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:57 [debug] 16085#0: worker cycle
2009/08/04 15:59:57 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:57 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:57 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:57 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:57 [debug] 16085#0: worker cycle
2009/08/04 15:59:57 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:57 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:58 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:58 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:58 [debug] 16085#0: worker cycle
2009/08/04 15:59:58 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:58 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:58 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:58 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:58 [debug] 16085#0: worker cycle
2009/08/04 15:59:58 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:58 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:59 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:59 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:59 [debug] 16085#0: worker cycle
2009/08/04 15:59:59 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:59 [debug] 16085#0: epoll timer: 500
2009/08/04 15:59:59 [debug] 16085#0: timer delta: 500
2009/08/04 15:59:59 [debug] 16085#0: posted events 00000000
2009/08/04 15:59:59 [debug] 16085#0: worker cycle
2009/08/04 15:59:59 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 15:59:59 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:00 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:00 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:00 [debug] 16085#0: worker cycle
2009/08/04 16:00:00 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:00 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:00 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:00 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:00 [debug] 16085#0: worker cycle
2009/08/04 16:00:00 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:00 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:01 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:01 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:01 [debug] 16085#0: worker cycle
2009/08/04 16:00:01 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:01 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:01 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:01 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:01 [debug] 16085#0: worker cycle
2009/08/04 16:00:01 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:01 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:02 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:02 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:02 [debug] 16085#0: worker cycle
2009/08/04 16:00:02 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:02 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:02 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:02 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:02 [debug] 16085#0: worker cycle
2009/08/04 16:00:02 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:02 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:03 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:03 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:03 [debug] 16085#0: worker cycle
2009/08/04 16:00:03 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:03 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:03 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:03 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:03 [debug] 16085#0: worker cycle
2009/08/04 16:00:03 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:03 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:04 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:04 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:04 [debug] 16085#0: worker cycle
2009/08/04 16:00:04 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:04 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:04 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:04 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:04 [debug] 16085#0: worker cycle
2009/08/04 16:00:04 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:04 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:05 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:05 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:05 [debug] 16085#0: worker cycle
2009/08/04 16:00:05 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:05 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:05 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:05 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:05 [debug] 16085#0: worker cycle
2009/08/04 16:00:05 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:05 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:06 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:06 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:06 [debug] 16085#0: worker cycle
2009/08/04 16:00:06 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:06 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:06 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:06 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:06 [debug] 16085#0: worker cycle
2009/08/04 16:00:06 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:06 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:07 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:07 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:07 [debug] 16085#0: worker cycle
2009/08/04 16:00:07 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:07 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:07 [debug] 16085#0: timer delta: 502
2009/08/04 16:00:07 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:07 [debug] 16085#0: worker cycle
2009/08/04 16:00:07 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:07 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:08 [debug] 16085#0: timer delta: 498
2009/08/04 16:00:08 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:08 [debug] 16085#0: worker cycle
2009/08/04 16:00:08 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:08 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:08 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:08 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:08 [debug] 16085#0: worker cycle
2009/08/04 16:00:08 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:08 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:09 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:09 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:09 [debug] 16085#0: worker cycle
2009/08/04 16:00:09 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:09 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:09 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:09 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:09 [debug] 16085#0: worker cycle
2009/08/04 16:00:09 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:09 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:10 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:10 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:10 [debug] 16085#0: worker cycle
2009/08/04 16:00:10 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:10 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:10 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:10 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:10 [debug] 16085#0: worker cycle
2009/08/04 16:00:10 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:10 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:11 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:11 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:11 [debug] 16085#0: worker cycle
2009/08/04 16:00:11 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:11 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:11 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:11 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:11 [debug] 16085#0: worker cycle
2009/08/04 16:00:11 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:11 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:12 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:12 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:12 [debug] 16085#0: worker cycle
2009/08/04 16:00:12 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:12 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:12 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:12 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:12 [debug] 16085#0: worker cycle
2009/08/04 16:00:12 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:12 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:13 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:13 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:13 [debug] 16085#0: worker cycle
2009/08/04 16:00:13 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:13 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:13 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:13 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:13 [debug] 16085#0: worker cycle
2009/08/04 16:00:13 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:13 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:14 [debug] 16085#0: timer delta: 502
2009/08/04 16:00:14 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:14 [debug] 16085#0: worker cycle
2009/08/04 16:00:14 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:14 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:14 [debug] 16085#0: timer delta: 498
2009/08/04 16:00:14 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:14 [debug] 16085#0: worker cycle
2009/08/04 16:00:14 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:14 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:15 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:15 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:15 [debug] 16085#0: worker cycle
2009/08/04 16:00:15 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:15 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:15 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:15 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:15 [debug] 16085#0: worker cycle
2009/08/04 16:00:15 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:15 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:16 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:16 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:16 [debug] 16085#0: worker cycle
2009/08/04 16:00:16 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:16 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:16 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:16 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:16 [debug] 16085#0: worker cycle
2009/08/04 16:00:16 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:16 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:17 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:17 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:17 [debug] 16085#0: worker cycle
2009/08/04 16:00:17 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:17 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:17 [debug] 16085#0: timer delta: 502
2009/08/04 16:00:17 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:17 [debug] 16085#0: worker cycle
2009/08/04 16:00:17 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:17 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:18 [debug] 16085#0: timer delta: 498
2009/08/04 16:00:18 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:18 [debug] 16085#0: worker cycle
2009/08/04 16:00:18 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:18 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:18 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:18 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:18 [debug] 16085#0: worker cycle
2009/08/04 16:00:18 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:18 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:19 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:19 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:19 [debug] 16085#0: worker cycle
2009/08/04 16:00:19 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:19 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:19 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:19 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:19 [debug] 16085#0: worker cycle
2009/08/04 16:00:19 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:19 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:20 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:20 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:20 [debug] 16085#0: worker cycle
2009/08/04 16:00:20 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:20 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:20 [debug] 16085#0: timer delta: 501
2009/08/04 16:00:20 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:20 [debug] 16085#0: worker cycle
2009/08/04 16:00:20 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:20 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:21 [debug] 16085#0: timer delta: 503
2009/08/04 16:00:21 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:21 [debug] 16085#0: worker cycle
2009/08/04 16:00:21 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:21 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:21 [debug] 16085#0: timer delta: 496
2009/08/04 16:00:21 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:21 [debug] 16085#0: worker cycle
2009/08/04 16:00:21 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:21 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:22 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:22 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:22 [debug] 16085#0: worker cycle
2009/08/04 16:00:22 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:22 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:22 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:22 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:22 [debug] 16085#0: worker cycle
2009/08/04 16:00:22 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:22 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:23 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:23 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:23 [debug] 16085#0: worker cycle
2009/08/04 16:00:23 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:23 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:23 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:23 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:23 [debug] 16085#0: worker cycle
2009/08/04 16:00:23 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:23 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:24 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:24 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:24 [debug] 16085#0: worker cycle
2009/08/04 16:00:24 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:24 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:24 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:24 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:24 [debug] 16085#0: worker cycle
2009/08/04 16:00:24 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:24 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:25 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:25 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:25 [debug] 16085#0: worker cycle
2009/08/04 16:00:25 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:25 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:25 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:25 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:25 [debug] 16085#0: worker cycle
2009/08/04 16:00:25 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:25 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:26 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:26 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:26 [debug] 16085#0: worker cycle
2009/08/04 16:00:26 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:26 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:26 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:26 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:26 [debug] 16085#0: worker cycle
2009/08/04 16:00:26 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:26 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:27 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:27 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:27 [debug] 16085#0: worker cycle
2009/08/04 16:00:27 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:27 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:27 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:27 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:27 [debug] 16085#0: worker cycle
2009/08/04 16:00:27 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:27 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:28 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:28 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:28 [debug] 16085#0: worker cycle
2009/08/04 16:00:28 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:28 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:28 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:28 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:28 [debug] 16085#0: worker cycle
2009/08/04 16:00:28 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:28 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:29 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:29 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:29 [debug] 16085#0: worker cycle
2009/08/04 16:00:29 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:29 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:29 [debug] 16085#0: timer delta: 512
2009/08/04 16:00:29 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:29 [debug] 16085#0: worker cycle
2009/08/04 16:00:29 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:29 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:30 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:30 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:30 [debug] 16085#0: worker cycle
2009/08/04 16:00:30 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:30 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:30 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:30 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:30 [debug] 16085#0: worker cycle
2009/08/04 16:00:30 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:30 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:31 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:31 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:31 [debug] 16085#0: worker cycle
2009/08/04 16:00:31 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:31 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:31 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:31 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:31 [debug] 16085#0: worker cycle
2009/08/04 16:00:31 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:31 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:32 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:32 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:32 [debug] 16085#0: worker cycle
2009/08/04 16:00:32 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:32 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:32 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:32 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:32 [debug] 16085#0: worker cycle
2009/08/04 16:00:32 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:32 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:33 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:33 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:33 [debug] 16085#0: worker cycle
2009/08/04 16:00:33 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:33 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:33 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:33 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:33 [debug] 16085#0: worker cycle
2009/08/04 16:00:33 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:33 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:34 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:34 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:34 [debug] 16085#0: worker cycle
2009/08/04 16:00:34 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:34 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:34 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:34 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:34 [debug] 16085#0: worker cycle
2009/08/04 16:00:34 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:34 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:35 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:35 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:35 [debug] 16085#0: worker cycle
2009/08/04 16:00:35 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:35 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:35 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:35 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:35 [debug] 16085#0: worker cycle
2009/08/04 16:00:35 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:35 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:36 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:36 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:36 [debug] 16085#0: worker cycle
2009/08/04 16:00:36 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:36 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:36 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:36 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:36 [debug] 16085#0: worker cycle
2009/08/04 16:00:36 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:36 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:37 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:37 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:37 [debug] 16085#0: worker cycle
2009/08/04 16:00:37 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:37 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:37 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:37 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:37 [debug] 16085#0: worker cycle
2009/08/04 16:00:37 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:37 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:38 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:38 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:38 [debug] 16085#0: worker cycle
2009/08/04 16:00:38 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:38 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:38 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:38 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:38 [debug] 16085#0: worker cycle
2009/08/04 16:00:38 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:38 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:39 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:39 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:39 [debug] 16085#0: worker cycle
2009/08/04 16:00:39 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:39 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:39 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:39 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:39 [debug] 16085#0: worker cycle
2009/08/04 16:00:39 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:39 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:40 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:40 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:40 [debug] 16085#0: worker cycle
2009/08/04 16:00:40 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:40 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:40 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:40 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:40 [debug] 16085#0: worker cycle
2009/08/04 16:00:40 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:40 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:41 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:41 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:41 [debug] 16085#0: worker cycle
2009/08/04 16:00:41 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:41 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:41 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:41 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:41 [debug] 16085#0: worker cycle
2009/08/04 16:00:41 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:41 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:42 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:42 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:42 [debug] 16085#0: worker cycle
2009/08/04 16:00:42 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:42 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:42 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:42 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:42 [debug] 16085#0: worker cycle
2009/08/04 16:00:42 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:42 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:43 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:43 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:43 [debug] 16085#0: worker cycle
2009/08/04 16:00:43 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:43 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:43 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:43 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:43 [debug] 16085#0: worker cycle
2009/08/04 16:00:43 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:43 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:44 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:44 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:44 [debug] 16085#0: worker cycle
2009/08/04 16:00:44 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:44 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:44 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:44 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:44 [debug] 16085#0: worker cycle
2009/08/04 16:00:44 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:44 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:45 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:45 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:45 [debug] 16085#0: worker cycle
2009/08/04 16:00:45 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:45 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:45 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:45 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:45 [debug] 16085#0: worker cycle
2009/08/04 16:00:45 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:45 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:46 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:46 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:46 [debug] 16085#0: worker cycle
2009/08/04 16:00:46 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:46 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:46 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:46 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:46 [debug] 16085#0: worker cycle
2009/08/04 16:00:46 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:46 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:47 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:47 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:47 [debug] 16085#0: worker cycle
2009/08/04 16:00:47 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:47 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:47 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:47 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:47 [debug] 16085#0: worker cycle
2009/08/04 16:00:47 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:47 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:48 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:48 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:48 [debug] 16085#0: worker cycle
2009/08/04 16:00:48 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:48 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:48 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:48 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:48 [debug] 16085#0: worker cycle
2009/08/04 16:00:48 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:48 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:49 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:49 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:49 [debug] 16085#0: worker cycle
2009/08/04 16:00:49 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:49 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:49 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:49 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:49 [debug] 16085#0: worker cycle
2009/08/04 16:00:49 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:49 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:50 [debug] 16084#0: epoll: fd:6 ev:0001 d:080D1BC0
2009/08/04 16:00:50 [debug] 16084#0: post event 080E8BC8
2009/08/04 16:00:50 [debug] 16084#0: timer delta: 73351
2009/08/04 16:00:50 [debug] 16084#0: posted event 080E8BC8
2009/08/04 16:00:50 [debug] 16084#0: delete posted event 080E8BC8
2009/08/04 16:00:50 [debug] 16084#0: accept on 0.0.0.0:81, ready: 0
2009/08/04 16:00:50 [debug] 16084#0: malloc: 080C9850:256
2009/08/04 16:00:50 [debug] 16084#0: *1 accept: 127.0.0.1 fd:10
2009/08/04 16:00:50 [debug] 16084#0: *1 event timer add: 10: 60000:3832394272
2009/08/04 16:00:50 [debug] 16084#0: *1 epoll add event: fd:10 op:1 ev:80000001
2009/08/04 16:00:50 [debug] 16084#0: posted event 00000000
2009/08/04 16:00:50 [debug] 16084#0: posted events 00000000
2009/08/04 16:00:50 [debug] 16084#0: worker cycle
2009/08/04 16:00:50 [debug] 16084#0: accept mutex locked
2009/08/04 16:00:50 [debug] 16084#0: epoll timer: 60000
2009/08/04 16:00:50 [debug] 16084#0: epoll: fd:10 ev:0001 d:080D1C78
2009/08/04 16:00:50 [debug] 16084#0: *1 post event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: timer delta: 1
2009/08/04 16:00:50 [debug] 16084#0: posted events 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: posted event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: *1 delete posted event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: *1 malloc: 080BF220:656
2009/08/04 16:00:50 [debug] 16084#0: *1 malloc: 080C53A0:1024
2009/08/04 16:00:50 [debug] 16084#0: *1 malloc: 080C57A8:4096
2009/08/04 16:00:50 [debug] 16084#0: *1 http process request line
2009/08/04 16:00:50 [debug] 16084#0: *1 recv: fd:10 382 of 1024
2009/08/04 16:00:50 [debug] 16084#0: *1 http request line: "GET / HTTP/1.1"
2009/08/04 16:00:50 [debug] 16084#0: *1 http uri: "/"
2009/08/04 16:00:50 [debug] 16084#0: *1 http args: ""
2009/08/04 16:00:50 [debug] 16084#0: *1 http exten: ""
2009/08/04 16:00:50 [debug] 16084#0: *1 http process request header line
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Host: localhost:81"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "User-Agent: Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.11) Gecko/2009060309 Ubuntu/8.04 (hardy) Firefox/3.0.11"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Accept-Language: en-us,en;q=0.5"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Accept-Encoding: gzip,deflate"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Keep-Alive: 300"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Connection: keep-alive"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header done
2009/08/04 16:00:50 [debug] 16084#0: *1 event timer del: 10: 3832394272
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 0
2009/08/04 16:00:50 [debug] 16084#0: *1 test location: "/"
2009/08/04 16:00:50 [debug] 16084#0: *1 using configuration "/"
2009/08/04 16:00:50 [debug] 16084#0: *1 http cl:-1 max:1048576
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 2
2009/08/04 16:00:50 [debug] 16084#0: *1 post rewrite phase: 3
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 4
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 5
2009/08/04 16:00:50 [debug] 16084#0: *1 access phase: 6
2009/08/04 16:00:50 [debug] 16084#0: *1 access phase: 7
2009/08/04 16:00:50 [debug] 16084#0: *1 post access phase: 8
2009/08/04 16:00:50 [debug] 16084#0: *1 content phase: 9
2009/08/04 16:00:50 [debug] 16084#0: *1 open index "/home/rainx/land/test/html/index.html"
2009/08/04 16:00:50 [debug] 16084#0: *1 internal redirect: "/index.html?"
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 0
2009/08/04 16:00:50 [debug] 16084#0: *1 test location: "/"
2009/08/04 16:00:50 [debug] 16084#0: *1 test location: "50x.html"
2009/08/04 16:00:50 [debug] 16084#0: *1 using configuration "/"
2009/08/04 16:00:50 [debug] 16084#0: *1 http cl:-1 max:1048576
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 2
2009/08/04 16:00:50 [debug] 16084#0: *1 post rewrite phase: 3
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 4
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 5
2009/08/04 16:00:50 [debug] 16084#0: *1 access phase: 6
2009/08/04 16:00:50 [debug] 16084#0: *1 access phase: 7
2009/08/04 16:00:50 [debug] 16084#0: *1 post access phase: 8
2009/08/04 16:00:50 [debug] 16084#0: *1 content phase: 9
2009/08/04 16:00:50 [debug] 16084#0: *1 content phase: 10
2009/08/04 16:00:50 [debug] 16084#0: *1 content phase: 11
2009/08/04 16:00:50 [debug] 16084#0: *1 http filename: "/home/rainx/land/test/html/index.html"
2009/08/04 16:00:50 [debug] 16084#0: *1 add cleanup: 080C5CEC
2009/08/04 16:00:50 [debug] 16084#0: *1 http static fd: 11
2009/08/04 16:00:50 [debug] 16084#0: *1 http set discard body
2009/08/04 16:00:50 [debug] 16084#0: *1 HTTP/1.1 200 OK

Server: nginx/0.7.61

Date: Tue, 04 Aug 2009 08:00:50 GMT

Content-Type: text/html

Content-Length: 151

Last-Modified: Tue, 04 Aug 2009 03:08:51 GMT

Connection: keep-alive

Accept-Ranges: bytes


2009/08/04 16:00:50 [debug] 16084#0: *1 write new buf t:1 f:0 080C5DF0, pos 080C5DF0, size: 216 file: 0, size: 0
2009/08/04 16:00:50 [debug] 16084#0: *1 http write filter: l:0 f:0 s:216
2009/08/04 16:00:50 [debug] 16084#0: *1 http output filter "/index.html?"
2009/08/04 16:00:50 [debug] 16084#0: *1 copy filter: "/index.html?"
2009/08/04 16:00:50 [debug] 16084#0: *1 http postpone filter "/index.html?" BF9D79D8
2009/08/04 16:00:50 [debug] 16084#0: *1 write old buf t:1 f:0 080C5DF0, pos 080C5DF0, size: 216 file: 0, size: 0
2009/08/04 16:00:50 [debug] 16084#0: *1 write new buf t:0 f:1 00000000, pos 00000000, size: 0 file: 0, size: 151
2009/08/04 16:00:50 [debug] 16084#0: *1 http write filter: l:1 f:0 s:367
2009/08/04 16:00:50 [debug] 16084#0: *1 http write filter limit 0
2009/08/04 16:00:50 [debug] 16084#0: *1 writev: 216
2009/08/04 16:00:50 [debug] 16084#0: *1 sendfile: @0 151
2009/08/04 16:00:50 [debug] 16084#0: *1 sendfile: 151, @0 151:151
2009/08/04 16:00:50 [debug] 16084#0: *1 http write filter 00000000
2009/08/04 16:00:50 [debug] 16084#0: *1 copy filter: 0 "/index.html?"
2009/08/04 16:00:50 [debug] 16084#0: *1 http finalize request: 0, "/index.html?" 1
2009/08/04 16:00:50 [debug] 16084#0: *1 set http keepalive handler
2009/08/04 16:00:50 [debug] 16084#0: *1 http close request
2009/08/04 16:00:50 [debug] 16084#0: *1 http log handler
2009/08/04 16:00:50 [debug] 16084#0: *1 run cleanup: 080C5CEC
2009/08/04 16:00:50 [debug] 16084#0: *1 file cleanup: fd:11
2009/08/04 16:00:50 [debug] 16084#0: *1 free: 080C57A8, unused: 1976
2009/08/04 16:00:50 [debug] 16084#0: *1 event timer add: 10: 65000:3832399273
2009/08/04 16:00:50 [debug] 16084#0: *1 free: 080BF220
2009/08/04 16:00:50 [debug] 16084#0: *1 free: 080C53A0
2009/08/04 16:00:50 [debug] 16084#0: *1 hc free: 00000000 0
2009/08/04 16:00:50 [debug] 16084#0: *1 hc busy: 00000000 0
2009/08/04 16:00:50 [debug] 16084#0: *1 tcp_nodelay
2009/08/04 16:00:50 [debug] 16084#0: *1 post event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: posted event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: *1 delete posted event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: *1 http keepalive handler
2009/08/04 16:00:50 [debug] 16084#0: *1 malloc: 080BF220:1024
2009/08/04 16:00:50 [debug] 16084#0: *1 recv: fd:10 -1 of 1024
2009/08/04 16:00:50 [debug] 16084#0: *1 recv() not ready (11: Resource temporarily unavailable)
2009/08/04 16:00:50 [debug] 16084#0: posted event 00000000
2009/08/04 16:00:50 [debug] 16084#0: worker cycle
2009/08/04 16:00:50 [debug] 16084#0: accept mutex locked
2009/08/04 16:00:50 [debug] 16084#0: epoll timer: 65000
2009/08/04 16:00:50 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:50 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:50 [debug] 16085#0: worker cycle
2009/08/04 16:00:50 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:50 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:50 [debug] 16084#0: epoll: fd:10 ev:0001 d:080D1C78
2009/08/04 16:00:50 [debug] 16084#0: *1 post event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: timer delta: 247
2009/08/04 16:00:50 [debug] 16084#0: posted events 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: posted event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: *1 delete posted event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: *1 http keepalive handler
2009/08/04 16:00:50 [debug] 16084#0: *1 recv: fd:10 363 of 1024
2009/08/04 16:00:50 [debug] 16084#0: *1 malloc: 080C53A0:656
2009/08/04 16:00:50 [debug] 16084#0: *1 malloc: 080C5638:4096
2009/08/04 16:00:50 [debug] 16084#0: *1 http process request line
2009/08/04 16:00:50 [debug] 16084#0: *1 http request line: "GET /favicon.ico HTTP/1.1"
2009/08/04 16:00:50 [debug] 16084#0: *1 http uri: "/favicon.ico"
2009/08/04 16:00:50 [debug] 16084#0: *1 http args: ""
2009/08/04 16:00:50 [debug] 16084#0: *1 http exten: "ico"
2009/08/04 16:00:50 [debug] 16084#0: *1 http process request header line
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Host: localhost:81"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "User-Agent: Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.11) Gecko/2009060309 Ubuntu/8.04 (hardy) Firefox/3.0.11"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Accept: image/png,image/*;q=0.8,*/*;q=0.5"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Accept-Language: en-us,en;q=0.5"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Accept-Encoding: gzip,deflate"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Keep-Alive: 300"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header: "Connection: keep-alive"
2009/08/04 16:00:50 [debug] 16084#0: *1 http header done
2009/08/04 16:00:50 [debug] 16084#0: *1 event timer del: 10: 3832399273
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 0
2009/08/04 16:00:50 [debug] 16084#0: *1 test location: "/"
2009/08/04 16:00:50 [debug] 16084#0: *1 test location: "50x.html"
2009/08/04 16:00:50 [debug] 16084#0: *1 using configuration "/"
2009/08/04 16:00:50 [debug] 16084#0: *1 http cl:-1 max:1048576
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 2
2009/08/04 16:00:50 [debug] 16084#0: *1 post rewrite phase: 3
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 4
2009/08/04 16:00:50 [debug] 16084#0: *1 generic phase: 5
2009/08/04 16:00:50 [debug] 16084#0: *1 access phase: 6
2009/08/04 16:00:50 [debug] 16084#0: *1 access phase: 7
2009/08/04 16:00:50 [debug] 16084#0: *1 post access phase: 8
2009/08/04 16:00:50 [debug] 16084#0: *1 content phase: 9
2009/08/04 16:00:50 [debug] 16084#0: *1 content phase: 10
2009/08/04 16:00:50 [debug] 16084#0: *1 content phase: 11
2009/08/04 16:00:50 [debug] 16084#0: *1 http filename: "/home/rainx/land/test/html/favicon.ico"
2009/08/04 16:00:50 [debug] 16084#0: *1 add cleanup: 080C5B58
2009/08/04 16:00:50 [error] 16084#0: *1 open() "/home/rainx/land/test/html/favicon.ico" failed (2: No such file or directory), client: 127.0.0.1, server: localhost, request: "GET /favicon.ico HTTP/1.1", host: "localhost:81"
2009/08/04 16:00:50 [debug] 16084#0: *1 http finalize request: 404, "/favicon.ico?" 1
2009/08/04 16:00:50 [debug] 16084#0: *1 http special response: 404, "/favicon.ico?"
2009/08/04 16:00:50 [debug] 16084#0: *1 http set discard body
2009/08/04 16:00:50 [debug] 16084#0: *1 HTTP/1.1 404 Not Found

Server: nginx/0.7.61

Date: Tue, 04 Aug 2009 08:00:50 GMT

Content-Type: text/html

Content-Length: 169

Connection: keep-alive


2009/08/04 16:00:50 [debug] 16084#0: *1 write new buf t:1 f:0 080C5BA4, pos 080C5BA4, size: 155 file: 0, size: 0
2009/08/04 16:00:50 [debug] 16084#0: *1 http write filter: l:0 f:0 s:155
2009/08/04 16:00:50 [debug] 16084#0: *1 http output filter "/favicon.ico?"
2009/08/04 16:00:50 [debug] 16084#0: *1 copy filter: "/favicon.ico?"
2009/08/04 16:00:50 [debug] 16084#0: *1 http postpone filter "/favicon.ico?" 080C5D00
2009/08/04 16:00:50 [debug] 16084#0: *1 write old buf t:1 f:0 080C5BA4, pos 080C5BA4, size: 155 file: 0, size: 0
2009/08/04 16:00:50 [debug] 16084#0: *1 write new buf t:0 f:0 00000000, pos 080B02C0, size: 116 file: 0, size: 0
2009/08/04 16:00:50 [debug] 16084#0: *1 write new buf t:0 f:0 00000000, pos 080AFD60, size: 53 file: 0, size: 0
2009/08/04 16:00:50 [debug] 16084#0: *1 http write filter: l:1 f:0 s:324
2009/08/04 16:00:50 [debug] 16084#0: *1 http write filter limit 0
2009/08/04 16:00:50 [debug] 16084#0: *1 writev: 324
2009/08/04 16:00:50 [debug] 16084#0: *1 http write filter 00000000
2009/08/04 16:00:50 [debug] 16084#0: *1 copy filter: 0 "/favicon.ico?"
2009/08/04 16:00:50 [debug] 16084#0: *1 http finalize request: 0, "/favicon.ico?" 1
2009/08/04 16:00:50 [debug] 16084#0: *1 set http keepalive handler
2009/08/04 16:00:50 [debug] 16084#0: *1 http close request
2009/08/04 16:00:50 [debug] 16084#0: *1 http log handler
2009/08/04 16:00:50 [debug] 16084#0: *1 free: 080C5638, unused: 2121
2009/08/04 16:00:50 [debug] 16084#0: *1 event timer add: 10: 65000:3832399520
2009/08/04 16:00:50 [debug] 16084#0: *1 free: 080C53A0
2009/08/04 16:00:50 [debug] 16084#0: *1 free: 080BF220
2009/08/04 16:00:50 [debug] 16084#0: *1 hc free: 00000000 0
2009/08/04 16:00:50 [debug] 16084#0: *1 hc busy: 00000000 0
2009/08/04 16:00:50 [debug] 16084#0: *1 post event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: posted event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: *1 delete posted event 080E8C30
2009/08/04 16:00:50 [debug] 16084#0: *1 http keepalive handler
2009/08/04 16:00:50 [debug] 16084#0: *1 malloc: 080BF220:1024
2009/08/04 16:00:50 [debug] 16084#0: *1 recv: fd:10 -1 of 1024
2009/08/04 16:00:50 [debug] 16084#0: *1 recv() not ready (11: Resource temporarily unavailable)
2009/08/04 16:00:50 [debug] 16084#0: posted event 00000000
2009/08/04 16:00:50 [debug] 16084#0: worker cycle
2009/08/04 16:00:50 [debug] 16084#0: accept mutex locked
2009/08/04 16:00:50 [debug] 16084#0: epoll timer: 65000
2009/08/04 16:00:50 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:50 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:50 [debug] 16085#0: worker cycle
2009/08/04 16:00:50 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:50 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:51 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:51 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:51 [debug] 16085#0: worker cycle
2009/08/04 16:00:51 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:51 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:51 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:51 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:51 [debug] 16085#0: worker cycle
2009/08/04 16:00:51 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:51 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:52 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:52 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:52 [debug] 16085#0: worker cycle
2009/08/04 16:00:52 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:52 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:52 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:52 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:52 [debug] 16085#0: worker cycle
2009/08/04 16:00:52 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:52 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:53 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:53 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:53 [debug] 16085#0: worker cycle
2009/08/04 16:00:53 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:53 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:53 [debug] 16084#0: epoll: fd:10 ev:0001 d:080D1C78
2009/08/04 16:00:53 [debug] 16084#0: *1 post event 080E8C30
2009/08/04 16:00:53 [debug] 16084#0: timer delta: 3051
2009/08/04 16:00:53 [debug] 16084#0: posted events 080E8C30
2009/08/04 16:00:53 [debug] 16084#0: posted event 080E8C30
2009/08/04 16:00:53 [debug] 16084#0: *1 delete posted event 080E8C30
2009/08/04 16:00:53 [debug] 16084#0: *1 http keepalive handler
2009/08/04 16:00:53 [debug] 16084#0: *1 recv: fd:10 393 of 1024
2009/08/04 16:00:53 [debug] 16084#0: *1 malloc: 080C53A0:656
2009/08/04 16:00:53 [debug] 16084#0: *1 malloc: 080C5638:4096
2009/08/04 16:00:53 [debug] 16084#0: *1 http process request line
2009/08/04 16:00:53 [debug] 16084#0: *1 http request line: "GET /favicon.ico HTTP/1.1"
2009/08/04 16:00:53 [debug] 16084#0: *1 http uri: "/favicon.ico"
2009/08/04 16:00:53 [debug] 16084#0: *1 http args: ""
2009/08/04 16:00:53 [debug] 16084#0: *1 http exten: "ico"
2009/08/04 16:00:53 [debug] 16084#0: *1 http process request header line
2009/08/04 16:00:53 [debug] 16084#0: *1 http header: "Host: localhost:81"
2009/08/04 16:00:53 [debug] 16084#0: *1 http header: "User-Agent: Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.11) Gecko/2009060309 Ubuntu/8.04 (hardy) Firefox/3.0.11"
2009/08/04 16:00:53 [debug] 16084#0: *1 http header: "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"
2009/08/04 16:00:53 [debug] 16084#0: *1 http header: "Accept-Language: en-us,en;q=0.5"
2009/08/04 16:00:53 [debug] 16084#0: *1 http header: "Accept-Encoding: gzip,deflate"
2009/08/04 16:00:53 [debug] 16084#0: *1 http header: "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7"
2009/08/04 16:00:53 [debug] 16084#0: *1 http header: "Keep-Alive: 300"
2009/08/04 16:00:53 [debug] 16084#0: *1 http header: "Connection: keep-alive"
2009/08/04 16:00:53 [debug] 16084#0: *1 http header done
2009/08/04 16:00:53 [debug] 16084#0: *1 event timer del: 10: 3832399520
2009/08/04 16:00:53 [debug] 16084#0: *1 generic phase: 0
2009/08/04 16:00:53 [debug] 16084#0: *1 test location: "/"
2009/08/04 16:00:53 [debug] 16084#0: *1 test location: "50x.html"
2009/08/04 16:00:53 [debug] 16084#0: *1 using configuration "/"
2009/08/04 16:00:53 [debug] 16084#0: *1 http cl:-1 max:1048576
2009/08/04 16:00:53 [debug] 16084#0: *1 generic phase: 2
2009/08/04 16:00:53 [debug] 16084#0: *1 post rewrite phase: 3
2009/08/04 16:00:53 [debug] 16084#0: *1 generic phase: 4
2009/08/04 16:00:53 [debug] 16084#0: *1 generic phase: 5
2009/08/04 16:00:53 [debug] 16084#0: *1 access phase: 6
2009/08/04 16:00:53 [debug] 16084#0: *1 access phase: 7
2009/08/04 16:00:53 [debug] 16084#0: *1 post access phase: 8
2009/08/04 16:00:53 [debug] 16084#0: *1 content phase: 9
2009/08/04 16:00:53 [debug] 16084#0: *1 content phase: 10
2009/08/04 16:00:53 [debug] 16084#0: *1 content phase: 11
2009/08/04 16:00:53 [debug] 16084#0: *1 http filename: "/home/rainx/land/test/html/favicon.ico"
2009/08/04 16:00:53 [debug] 16084#0: *1 add cleanup: 080C5B58
2009/08/04 16:00:53 [error] 16084#0: *1 open() "/home/rainx/land/test/html/favicon.ico" failed (2: No such file or directory), client: 127.0.0.1, server: localhost, request: "GET /favicon.ico HTTP/1.1", host: "localhost:81"
2009/08/04 16:00:53 [debug] 16084#0: *1 http finalize request: 404, "/favicon.ico?" 1
2009/08/04 16:00:53 [debug] 16084#0: *1 http special response: 404, "/favicon.ico?"
2009/08/04 16:00:53 [debug] 16084#0: *1 http set discard body
2009/08/04 16:00:53 [debug] 16084#0: *1 HTTP/1.1 404 Not Found

Server: nginx/0.7.61

Date: Tue, 04 Aug 2009 08:00:53 GMT

Content-Type: text/html

Content-Length: 169

Connection: keep-alive


2009/08/04 16:00:53 [debug] 16084#0: *1 write new buf t:1 f:0 080C5BA4, pos 080C5BA4, size: 155 file: 0, size: 0
2009/08/04 16:00:53 [debug] 16084#0: *1 http write filter: l:0 f:0 s:155
2009/08/04 16:00:53 [debug] 16084#0: *1 http output filter "/favicon.ico?"
2009/08/04 16:00:53 [debug] 16084#0: *1 copy filter: "/favicon.ico?"
2009/08/04 16:00:53 [debug] 16084#0: *1 http postpone filter "/favicon.ico?" 080C5D00
2009/08/04 16:00:53 [debug] 16084#0: *1 write old buf t:1 f:0 080C5BA4, pos 080C5BA4, size: 155 file: 0, size: 0
2009/08/04 16:00:53 [debug] 16084#0: *1 write new buf t:0 f:0 00000000, pos 080B02C0, size: 116 file: 0, size: 0
2009/08/04 16:00:53 [debug] 16084#0: *1 write new buf t:0 f:0 00000000, pos 080AFD60, size: 53 file: 0, size: 0
2009/08/04 16:00:53 [debug] 16084#0: *1 http write filter: l:1 f:0 s:324
2009/08/04 16:00:53 [debug] 16084#0: *1 http write filter limit 0
2009/08/04 16:00:53 [debug] 16084#0: *1 writev: 324
2009/08/04 16:00:53 [debug] 16084#0: *1 http write filter 00000000
2009/08/04 16:00:53 [debug] 16084#0: *1 copy filter: 0 "/favicon.ico?"
2009/08/04 16:00:53 [debug] 16084#0: *1 http finalize request: 0, "/favicon.ico?" 1
2009/08/04 16:00:53 [debug] 16084#0: *1 set http keepalive handler
2009/08/04 16:00:53 [debug] 16084#0: *1 http close request
2009/08/04 16:00:53 [debug] 16084#0: *1 http log handler
2009/08/04 16:00:53 [debug] 16084#0: *1 free: 080C5638, unused: 2121
2009/08/04 16:00:53 [debug] 16084#0: *1 event timer add: 10: 65000:3832402571
2009/08/04 16:00:53 [debug] 16084#0: *1 free: 080C53A0
2009/08/04 16:00:53 [debug] 16084#0: *1 free: 080BF220
2009/08/04 16:00:53 [debug] 16084#0: *1 hc free: 00000000 0
2009/08/04 16:00:53 [debug] 16084#0: *1 hc busy: 00000000 0
2009/08/04 16:00:53 [debug] 16084#0: *1 post event 080E8C30
2009/08/04 16:00:53 [debug] 16084#0: posted event 080E8C30
2009/08/04 16:00:53 [debug] 16084#0: *1 delete posted event 080E8C30
2009/08/04 16:00:53 [debug] 16084#0: *1 http keepalive handler
2009/08/04 16:00:53 [debug] 16084#0: *1 malloc: 080BF220:1024
2009/08/04 16:00:53 [debug] 16084#0: *1 recv: fd:10 -1 of 1024
2009/08/04 16:00:53 [debug] 16084#0: *1 recv() not ready (11: Resource temporarily unavailable)
2009/08/04 16:00:53 [debug] 16084#0: posted event 00000000
2009/08/04 16:00:53 [debug] 16084#0: worker cycle
2009/08/04 16:00:53 [debug] 16084#0: accept mutex locked
2009/08/04 16:00:53 [debug] 16084#0: epoll timer: 65000
2009/08/04 16:00:53 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:53 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:53 [debug] 16085#0: worker cycle
2009/08/04 16:00:53 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:53 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:54 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:54 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:54 [debug] 16085#0: worker cycle
2009/08/04 16:00:54 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:54 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:54 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:54 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:54 [debug] 16085#0: worker cycle
2009/08/04 16:00:54 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:54 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:55 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:55 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:55 [debug] 16085#0: worker cycle
2009/08/04 16:00:55 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:55 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:55 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:55 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:55 [debug] 16085#0: worker cycle
2009/08/04 16:00:55 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:55 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:56 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:56 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:56 [debug] 16085#0: worker cycle
2009/08/04 16:00:56 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:56 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:56 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:56 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:56 [debug] 16085#0: worker cycle
2009/08/04 16:00:56 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:56 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:57 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:57 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:57 [debug] 16085#0: worker cycle
2009/08/04 16:00:57 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:57 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:57 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:57 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:57 [debug] 16085#0: worker cycle
2009/08/04 16:00:57 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:57 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:58 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:58 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:58 [debug] 16085#0: worker cycle
2009/08/04 16:00:58 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:58 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:58 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:58 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:58 [debug] 16085#0: worker cycle
2009/08/04 16:00:58 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:58 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:59 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:59 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:59 [debug] 16085#0: worker cycle
2009/08/04 16:00:59 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:59 [debug] 16085#0: epoll timer: 500
2009/08/04 16:00:59 [debug] 16085#0: timer delta: 500
2009/08/04 16:00:59 [debug] 16085#0: posted events 00000000
2009/08/04 16:00:59 [debug] 16085#0: worker cycle
2009/08/04 16:00:59 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:00:59 [debug] 16085#0: epoll timer: 500
2009/08/04 16:01:00 [debug] 16085#0: timer delta: 500
2009/08/04 16:01:00 [debug] 16085#0: posted events 00000000
2009/08/04 16:01:00 [debug] 16085#0: worker cycle
2009/08/04 16:01:00 [debug] 16085#0: accept mutex lock failed: 0
2009/08/04 16:01:00 [debug] 16085#0: epoll timer: 500
2009/08/04 16:01:00 [notice] 17681#0: signal process started
2009/08/04 16:01:00 [notice] 16083#0: signal 15 (SIGTERM) received, exiting
2009/08/04 16:01:00 [debug] 16083#0: wake up
2009/08/04 16:01:00 [debug] 16083#0: child: 0 16084 e:0 t:0 d:0 r:1 j:0
2009/08/04 16:01:00 [debug] 16083#0: child: 1 16085 e:0 t:0 d:0 r:1 j:0
2009/08/04 16:01:00 [debug] 16083#0: temination cycle: 100
2009/08/04 16:01:00 [debug] 16083#0: sigsuspend
2009/08/04 16:01:00 [debug] 16084#0: epoll: fd:8 ev:0001 d:080D1C1C
2009/08/04 16:01:00 [debug] 16084#0: post event 080E8BFC
2009/08/04 16:01:00 [debug] 16084#0: timer delta: 7153
2009/08/04 16:01:00 [debug] 16084#0: posted events 080E8BFC
2009/08/04 16:01:00 [debug] 16084#0: posted event 080E8BFC
2009/08/04 16:01:00 [debug] 16084#0: delete posted event 080E8BFC
2009/08/04 16:01:00 [debug] 16084#0: channel handler
2009/08/04 16:01:00 [debug] 16084#0: channel: 16
2009/08/04 16:01:00 [debug] 16084#0: channel command: 4
2009/08/04 16:01:00 [debug] 16084#0: channel: -2
2009/08/04 16:01:00 [debug] 16084#0: posted event 00000000
2009/08/04 16:01:00 [notice] 16084#0: exiting
2009/08/04 16:01:00 [debug] 16084#0: flush files
2009/08/04 16:01:00 [debug] 16084#0: run cleanup: 080CCBA0
2009/08/04 16:01:00 [debug] 16084#0: cleanup resolver
2009/08/04 16:01:00 [debug] 16084#0: free: 080BFB90, unused: 0
2009/08/04 16:01:00 [debug] 16084#0: free: 080C9BB0, unused: 0
2009/08/04 16:01:00 [debug] 16084#0: free: 080CDBB8, unused: 12796
2009/08/04 16:01:00 [notice] 16084#0: exit
2009/08/04 16:01:00 [debug] 16085#0: epoll: fd:10 ev:0001 d:080D1C1C
2009/08/04 16:01:00 [debug] 16085#0: channel handler
2009/08/04 16:01:00 [debug] 16085#0: channel: 16
2009/08/04 16:01:00 [debug] 16085#0: channel command: 4
2009/08/04 16:01:00 [debug] 16085#0: channel: -2
2009/08/04 16:01:00 [debug] 16085#0: timer delta: 293
2009/08/04 16:01:00 [debug] 16085#0: posted events 00000000
2009/08/04 16:01:00 [notice] 16085#0: exiting
2009/08/04 16:01:00 [debug] 16085#0: flush files
2009/08/04 16:01:00 [debug] 16085#0: run cleanup: 080CCBA0
2009/08/04 16:01:00 [debug] 16085#0: cleanup resolver
2009/08/04 16:01:00 [debug] 16085#0: free: 080BFB90, unused: 0
2009/08/04 16:01:00 [debug] 16085#0: free: 080C9BB0, unused: 0
2009/08/04 16:01:00 [debug] 16085#0: free: 080CDBB8, unused: 12796
2009/08/04 16:01:00 [notice] 16085#0: exit
2009/08/04 16:01:00 [notice] 16083#0: signal 17 (SIGCHLD) received
2009/08/04 16:01:00 [notice] 16083#0: worker process 16084 exited with code 0
2009/08/04 16:01:00 [notice] 16083#0: worker process 16085 exited with code 0
2009/08/04 16:01:00 [debug] 16083#0: wake up
2009/08/04 16:01:00 [debug] 16083#0: reap children
2009/08/04 16:01:00 [debug] 16083#0: child: 0 16084 e:1 t:1 d:0 r:1 j:0
2009/08/04 16:01:00 [debug] 16083#0: child: 1 16085 e:1 t:1 d:0 r:1 j:0
2009/08/04 16:01:00 [notice] 16083#0: exit
2009/08/04 16:01:00 [debug] 16083#0: run cleanup: 080CCBA0
2009/08/04 16:01:00 [debug] 16083#0: cleanup resolver
2009/08/04 16:01:00 [debug] 16083#0: free: 080BFB90, unused: 0
2009/08/04 16:01:00 [debug] 16083#0: free: 080C9BB0, unused: 0
2009/08/04 16:01:00 [debug] 16083#0: free: 080CDBB8, unused: 12801
```