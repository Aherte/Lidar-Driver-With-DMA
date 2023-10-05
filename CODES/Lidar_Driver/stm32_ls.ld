ENTRY(Reset_handler)
MEMORY
{
	FLASH(rx):ORIGIN = 0x08000000,LENGTH = 512K
	SRAM(rwx):ORIGIN = 0x20000000,LENGTH = 96K
}
SECTIONS
{
	.text :                  /* text bölümü flash'ın başlangıcı olan 0x08000000 adresinden başlar */
	{
		_stext = .; 
		*(.isr_vector)    /* flash hafızasında vector table text bölümünden altta kaldığı için önce vector table birleştirilmeli. */
		*(.text)         /* yıldız işareti bütün input dosyalarını .text dosyasında birleştirme anlamına gelir. */
		*(.rodata)
		. = ALIGN(4);
		_etext = .;      /* location counter (vma yı takip eder) için text bölümünün bittiği adresi gösterir. */
		
	}> FLASH                 /* (> vma AT> lma) virtual ve load memory adress. burda vma ve lma aynı oldugu için atama yapmadık. */
	
	.data :
	{
		_sdata = .;      /* burdaki adres sram in başlangıcı olan 0x20000000 adresi */
		*(.data)
		. = ALIGN(4);
		_edata = .;
	}> SRAM AT> FLASH        /* load adresi flash da oluşturur ama gerçek adresi sram e atar. */
	
	.bss :
	{
		_sbss = .;
		*(.bss)
		*(COMMON) 
		. = ALIGN(4);   /* son adresi tek sayı bırakmamak için kaydırma yapıyoruz.    */
		_ebss = .;
	}> SRAM

}
