param (
    [Parameter(Mandatory=$true)][string]$version
)

$target="vccwallet-v$version"

Remove-Item -Path release/wininstaller -Recurse -ErrorAction Ignore  | Out-Null
New-Item release/wininstaller -itemtype directory                    | Out-Null

Copy-Item release/$target/vccwallet.exe     release/wininstaller/
Copy-Item release/$target/LICENSE           release/wininstaller/
Copy-Item release/$target/README.md         release/wininstaller/
Copy-Item release/$target/vcoind.exe        release/wininstaller/
Copy-Item release/$target/vcoin-cli.exe     release/wininstaller/

Get-Content src/scripts/vcc-qt-wallet.wxs | ForEach-Object { $_ -replace "RELEASE_VERSION", "$version" } | Out-File -Encoding utf8 release/wininstaller/vcc-qt-wallet.wxs

candle.exe release/wininstaller/vcc-qt-wallet.wxs -o release/wininstaller/vcc-qt-wallet.wixobj 
if (!$?) {
    exit 1;
}

light.exe -ext WixUIExtension -cultures:en-us release/wininstaller/vcc-qt-wallet.wixobj -out release/wininstaller/vccwallet.msi 
if (!$?) {
    exit 1;
}

New-Item artifacts -itemtype directory -Force | Out-Null
Copy-Item release/wininstaller/vccwallet.msi ./artifacts/Windows-installer-$target.msi