import cv2

image = cv2.imread('deteksi.tepi.jpg')
if image is None:
    print("Error: Gambar tidak ditemukan. Pastikan file 'deteksi.tepi.jpg' ada di folder yang sama.")
    exit()

gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

blurred = cv2.GaussianBlur(gray, (5, 5), 0)

edges = cv2.Canny(blurred, 50, 150)

cv2.imwrite('output_edges.jpg', edges)

print("Deteksi tepi selesai. Hasil disimpan sebagai 'output_edges.jpg'.")