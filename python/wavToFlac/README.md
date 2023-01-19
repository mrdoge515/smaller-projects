# wavToFlac.py
Python scripts automating wave to flac conversion.
## Requirements
* Python 3.10.9 and up
* ffmpeg (in $path)
* Discogs API key
## How to use?
1. Download this project and unzip it
2. Open your terminal emulator (console) in the unziped files directory and type <code>pip install -r requirements.txt</code>
3. Now you have to edit a few lines, which are: 
    * numberOfSongs
    * musicLibrary - full path to your main folder with albums
    * folderName - path (relative to musicLibrary) to the album you want to convert
    * discog = discog = dis...(user_token=)
4. Now you can start the script by typing <script>python wavToFlac.py</script> and follow instructions on screen