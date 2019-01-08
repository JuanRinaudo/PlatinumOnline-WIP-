@echo off

call buildClient.bat
pushd ..
pushd Build
pushd Client
pushd Windows
devenv Client.exe
popd
popd
popd
popd