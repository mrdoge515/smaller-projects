import os
import discogs_client
from mutagen.flac import FLAC

# Settings
numberOfSongs = 0 #number of songs in the album
musicLibrary = r"[music_library]"
folderName = r"[album_folder_name]"

# Initializing discog client
discog = discogs_client.Client(user_agent='FooBarApp', user_token='yout_discog_token')

# Function that returns release number
def getRelease():
    results = discog.search(folderName, type='release')
    print(results.page(1)[1].title)
    if input("Is this the correct album title and artist? (y/N): ") == 'y':
        return results.page(1)[1].id
    
# Function that fetches data about specified album
def getReleaseData(releaseNum):
    release = discog.release(releaseNum)
    return release

# Function that adds 0 before number for compatibility reasons
def convertNum(num):
    if num < 10:
        return "0" + str(num)
    else:
        return str(num)

def addTags(path, release, trackNum):
    audio = FLAC(path)
    audio["ALBUM"] = release.title
    audio["ARTIST"] = release.artists[0].name
    audio["YEAR"] = str(release.year)
    audio["TITLE"] = release.tracklist[trackNum - 1].title
    audio.save()

# Main function
def main():
    releaseNumber = getRelease()
    release = getReleaseData(releaseNumber)

    # Check if output folder exists, if not create it
    if os.path.exists(folderName) == False:
        os.mkdir('./' + folderName)

    # Convert all wav songs to flac
    for x in range(1, numberOfSongs + 1):
        try:
            os.system('ffmpeg -i "' + str(musicLibrary + folderName) + r'/audio_' + convertNum(x) +'.wav" -af aformat=s16:44100 "./'+ folderName + '/audio_' + convertNum(x) + '.flac"')
            addTags("./" + folderName + "/audio_" + convertNum(x) + ".flac", release, x)
        except:
            print("Error")
    

# If this file is a main file, execute main()
if __name__ == '__main__':
    main()