# Midterm
Midterm: main.o MusicPlayer.o SimpleSnakesAndLadders.o SnakesAndLaddersCLIView.o SnakesAndLaddersCLIController.o MusicPlayer.o Board.o BoardBuilder.o Player.o ComPlayer.o SnakeLadder.o libDE1SoCfpga.a
	g++ -o Midterm main.o MusicPlayer.o SimpleSnakesAndLadders.o SnakesAndLaddersCLIView.o SnakesAndLaddersCLIController.o Board.o BoardBuilder.o Player.o ComPlayer.o SnakeLadder.o libDE1SoCfpga.a

# Clean
clean:
	rm -f *.o *.a Midterm



# Main program:
main.o: src/main.cpp
	g++ -g -I lib/DE1SoCfpga/include -lDE1SoCfpga -c src/main.cpp

# SnakesAndLadders
SnakesAndLaddersCLIController.o: src/SnakesAndLadders/Controller/SnakesAndLaddersCLIController.h src/SnakesAndLadders/Controller/SnakesAndLaddersCLIController.cpp
	g++ -g -c src/SnakesAndLadders/Controller/SnakesAndLaddersCLIController.cpp

SnakesAndLaddersCLIView.o: src/SnakesAndLadders/Model/SnakesAndLaddersModel.h src/SnakesAndLadders/View/SnakesAndLaddersView.h src/SnakesAndLadders/View/SnakesAndLaddersCLIView.h src/SnakesAndLadders/View/SnakesAndLaddersCLIView.cpp
	g++ -g -c -I lib/DE1SoCfpga/include src/SnakesAndLadders/View/SnakesAndLaddersCLIView.cpp

SimpleSnakesAndLadders.o: src/SnakesAndLadders/Model/SnakesAndLaddersModel.h src/SnakesAndLadders/Model/SimpleSnakesAndLadders/SimpleSnakesAndLadders.h src/SnakesAndLadders/Model/SimpleSnakesAndLadders/SimpleSnakesAndLadders.cpp
	g++ -g -I lib/DE1SoCfpga/include -c src/SnakesAndLadders/Model/SimpleSnakesAndLadders/SimpleSnakesAndLadders.cpp

ComPlayer.o: Player.o src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Player/ComPlayer.h src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Player/ComPlayer.cpp
	g++ -g -I lib/DE1SoCfpga/include -c src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Player/ComPlayer.cpp

Player.o: src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Player/Player.h src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Player/Player.cpp
	g++ -g -I lib/DE1SoCfpga/include -c src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Player/Player.cpp

BoardBuilder.o: src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/BoardBuilder.h src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/BoardBuilder.cpp
	g++ -g -c src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/BoardBuilder.cpp

Board.o: src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/Board.h src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/Board.cpp
	g++ -g -c src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/Board.cpp

SnakeLadder.o: src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/SnakeLadder.h src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/SnakeLadder.cpp
	g++ -g -c src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/SnakeLadder.cpp

# MusicPlayer
MusicPlayer.o: src/MusicPlayer/MusicPlayer.h src/MusicPlayer/MusicPlayer.cpp
	g++ -g -I lib/DE1SoCfpga/include -c src/MusicPlayer/MusicPlayer.cpp



# DE1SoCfpga Library:
libDE1SoCfpga.a: Speaker.o ExpansionPort.o LED.o MPCoreTimer.o PushButton.o SevenSegment.o Switch.o Device.o DE1SoCfpga.o
	ar rvs libDE1SoCfpga.a Speaker.o ExpansionPort.o LED.o MPCoreTimer.o PushButton.o SevenSegment.o Switch.o Device.o DE1SoCfpga.o

Speaker.o: lib/DE1SoCfpga/include/DE1SoCfpga/Device/Speaker.h lib/DE1SoCfpga/src/DE1SoCfpga/Device/Speaker.cpp lib/DE1SoCfpga/src/DE1SoCfpga/BitOperations.h
	g++ -g -I lib/DE1SoCfpga/include -I lib/DE1SoCfpga/src -c lib/DE1SoCfpga/src/DE1SoCfpga/Device/Speaker.cpp

ExpansionPort.o: lib/DE1SoCfpga/include/DE1SoCfpga/Device/ExpansionPort.h lib/DE1SoCfpga/src/DE1SoCfpga/Device/ExpansionPort.cpp lib/DE1SoCfpga/src/DE1SoCfpga/BitOperations.h
	g++ -g -I lib/DE1SoCfpga/include -I lib/DE1SoCfpga/src -c lib/DE1SoCfpga/src/DE1SoCfpga/Device/ExpansionPort.cpp

LED.o: lib/DE1SoCfpga/include/DE1SoCfpga/Device/LED.h lib/DE1SoCfpga/src/DE1SoCfpga/Device/Device.cpp
	g++ -g -I lib/DE1SoCfpga/include -I lib/DE1SoCfpga/src -c lib/DE1SoCfpga/src/DE1SoCfpga/Device/LED.cpp

MPCoreTimer.o: lib/DE1SoCfpga/include/DE1SoCfpga/Device/MPCoreTimer.h lib/DE1SoCfpga/src/DE1SoCfpga/Device/MPCoreTimer.cpp
	g++ -g -I lib/DE1SoCfpga/include -I lib/DE1SoCfpga/src -c lib/DE1SoCfpga/src/DE1SoCfpga/Device/MPCoreTimer.cpp

PushButton.o: lib/DE1SoCfpga/include/DE1SoCfpga/Device/PushButton.h lib/DE1SoCfpga/src/DE1SoCfpga/Device/PushButton.cpp
	g++ -g -I lib/DE1SoCfpga/include -I lib/DE1SoCfpga/src -c lib/DE1SoCfpga/src/DE1SoCfpga/Device/PushButton.cpp

SevenSegment.o: lib/DE1SoCfpga/include/DE1SoCfpga/Device/SevenSegment.h lib/DE1SoCfpga/src/DE1SoCfpga/Device/SevenSegment.cpp
	g++ -g -I lib/DE1SoCfpga/include -I lib/DE1SoCfpga/src -c lib/DE1SoCfpga/src/DE1SoCfpga/Device/SevenSegment.cpp

Switch.o: lib/DE1SoCfpga/include/DE1SoCfpga/Device/Switch.h lib/DE1SoCfpga/src/DE1SoCfpga/Device/Switch.cpp
	g++ -g -I lib/DE1SoCfpga/include -I lib/DE1SoCfpga/src -c lib/DE1SoCfpga/src/DE1SoCfpga/Device/Switch.cpp

Device.o: lib/DE1SoCfpga/include/DE1SoCfpga/Device/Device.h lib/DE1SoCfpga/src/DE1SoCfpga/Device/Device.cpp
	g++ -g -I lib/DE1SoCfpga/include -I lib/DE1SoCfpga/src -c lib/DE1SoCfpga/src/DE1SoCfpga/Device/Device.cpp

DE1SoCfpga.o: lib/DE1SoCfpga/include/DE1SoCfpga/DE1SoCfpga.h lib/DE1SoCfpga/src/DE1SoCfpga/DE1SoCfpga.cpp
	g++ -g -I lib/DE1SoCfpga/include -I lib/DE1SoCfpga/src -c lib/DE1SoCfpga/src/DE1SoCfpga/DE1SoCfpga.cpp