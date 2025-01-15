#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TRACK 100
typedef struct
{
    int id;
    char title[20];
    char artist[20];
    char genre[20];
    float duration;

} MusicTrack;
MusicTrack tracks[MAX_TRACK];
int trackCount = 0;

void addMusicTrack()
{
    if (trackCount >= MAX_TRACK)
    {
        printf("Cannot add more tracks. Maximum limit reached.\n");
    }
    else
    {
        MusicTrack track;
        printf("Enter the id of track\n");
        scanf("%d", &track.id);
        getchar();
        printf("Enter track title\n");
        fgets(track.title, sizeof(track.title), stdin);
        track.title[strcspn(track.title, "\n")] = 0;

        printf("Enter track artist\n");
        fgets(track.artist, sizeof(track.artist), stdin);
        track.artist[strcspn(track.artist, "\n")] = 0;

        printf("Enter track genre\n");
        fgets(track.genre, sizeof(track.genre), stdin);
        track.genre[strcspn(track.genre, "\n")] = 0;

        printf("Enter the duration of song\n");
        scanf("%f", &track.duration);

        tracks[trackCount++] = track;
        printf("Music added successfully\n");
    }
}

void deleteMusicTrack()
{
    int id;
    int found = 0;
    printf("Enter the id of music you want to delete\n");
    scanf("%d", &id);

    for (int index = 0; index < trackCount; index++)
    {
        if (tracks[index].id == id)
        {
            for (int index1 = index; index1 < trackCount - 1; index1++)
            {
                tracks[index1] = tracks[index1 + 1];
            }
            trackCount--;
            found = 1;
            printf("Track deleted successfully\n");
            break;
        }
    }
    if (!found)
    {
        printf("Track not found with this id\n");
    }
}

void displayAllMusicTrack()
{
    if (trackCount == 0)
    {
        printf("No track is available to display\n");
    }
    else
    {
        for (int index = 0; index < trackCount; index++)
        {
            printf("ID: %d ,Title: %s,Artist: %s,Genre: %s,Duration: %.2f \n ", tracks[index].id, tracks[index].title, tracks[index].artist, tracks[index].genre, tracks[index].duration);
        }
    }
}

void searchMusicTrack()
{
    if (trackCount == 0)
    {
        printf("No track is available to search\n");
    }
    else
    {
        int id;
        int found = 0;
        printf("Enter the id of track for search\n");
        scanf("%d", &id);
        for (int index = 0; index < trackCount; index++)
        {
            if (tracks[index].id == id)
            {
                printf("ID: %d ,Title: %s,Artist: %s,Genre: %s,Duration: %.2f \n ", tracks[index].id, tracks[index].title, tracks[index].artist, tracks[index].genre, tracks[index].duration);
                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf("Track not found with this id\n");
        }
    }
}

void sortAllMusicTrack()
{
    MusicTrack temp;
    for (int index1 = 0; index1 < trackCount; index1++)
    {
        for (int index2 = index1 + 1; index2 < trackCount; index2++)
        {
            if (strcmp(tracks[index1].title, tracks[index2].title) > 0)
            {
                temp = tracks[index1];
                tracks[index1] = tracks[index2];
                tracks[index2] = temp;
            }
        }
    }
    printf("Music tracks sorted by Title successfully.\n");
}
int main()
{
    int choice;
    do
    {
        printf("\nMusic List Management System\n");
        printf("1. Add Music Track\n");
        printf("2. Delete Music Track\n");
        printf("3. Display All Music Tracks\n");
        printf("4. Search for Music Track\n");
        printf("5. Sort Music Tracks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addMusicTrack();
            break;
        case 2:
            deleteMusicTrack();
            break;
        case 3:
            displayAllMusicTrack();
            break;
        case 4:
            searchMusicTrack();
            break;
        case 5:
            sortAllMusicTrack();
            break;
        case 6:
            printf("Existing from current program\n");
            break;
        case 7:
            exit(0);
        }
    } while (choice != 6);
    return 0;
}