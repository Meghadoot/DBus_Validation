
Compile: 

>> gcc dbus_sender.c -o dbus_sender `pkg-config --cflags --libs dbus-1`
>> gcc dbus_receiver.c -o dbus_receiver `pkg-config --cflags --libs dbus-1`

Test: 

Step 1 (In terminal #1) - ./dbus_receiver  
Step 2 (In terminal #2) - ./dbus_sender

Expected Output: 

"Received signal: Hello from Sender!" in terminal #1

