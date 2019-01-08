@echo off

call buildClient.bat
pushd ..
pushd Build
pushd Client
pushd Windows
Client.exe
popd
popd
popd
popd