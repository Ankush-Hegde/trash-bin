
to create a pod run
```
$kubectl apply -f simple-pod.yaml
pod/nginx created

$kubectl get pods
NAME    READY   STATUS              RESTARTS   AGE
nginx   0/1     ContainerCreating   0          7s
```