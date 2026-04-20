FROM mcr.microsoft.com/dotnet/sdk:8.0

RUN dotnet publish -c Release -o out